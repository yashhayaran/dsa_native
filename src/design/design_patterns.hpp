#include <iostream>
#include <vector>

namespace Design
{
    namespace LLD
    {
        namespace Creational
        {
            namespace AbstractFactory
            {
                class Car
                {
                    protected:
                        size_t _nID;
                        bool _isManualOrAutomatic;

                    public: 
                        Car (const size_t nID, const bool isManualOrAutomatic): _nID(nID), _isManualOrAutomatic(isManualOrAutomatic)
                        { }
                        const size_t GetId()
                        {
                            return _nID;
                        }

                        const size_t IsAutomatic()
                        {
                            return _nID;
                        }

                        virtual void Drive() = 0;
                };

                class ElectricCar : public Car
                {
                    public: 
                        ElectricCar(const size_t nID, const bool isManualOrAutomatic): Car(nID, isManualOrAutomatic)
                        { }
                        
                        void Drive() 
                        {
                            std::cout << "Riding Electric car: " << _nID << std::endl;
                        }
                };

                class DieselCar : public Car
                {
                    public: 
                        DieselCar(const size_t nID, const bool isManualOrAutomatic): Car(nID, isManualOrAutomatic)
                        { }

                        void Drive() 
                        {
                            std::cout << "Riding Diesel car: " << _nID << std::endl;
                        }
                };

                class PetrolCar : public Car
                {
                    public: 
                        PetrolCar(const size_t nID, const bool isManualOrAutomatic): Car(nID, isManualOrAutomatic)
                        { }
                        
                        void Drive() 
                        {
                            std::cout << "Riding Petrol car: " << _nID << std::endl;
                        }
                };

                class IFactory 
                {
                    protected: 
                        static size_t _nTotal;
                    public: 
                        IFactory() 
                        {
                            _nTotal++;
                        }

                        virtual Car* BuildElectricCar() = 0;
                        virtual Car* BuildDieselCar() = 0;
                        virtual Car* BuildPetrolCar() = 0;
                };
                size_t IFactory::_nTotal = 0;

                class ManualCarFactory : public IFactory
                {
                    public: 
                        Car* BuildElectricCar()
                        {
                            return new ElectricCar(_nTotal, false);
                        }

                        Car* BuildDieselCar()
                        {
                            return new DieselCar(_nTotal, false);
                        }

                        Car* BuildPetrolCar()
                        {
                            return new PetrolCar(_nTotal, false);
                        }
                };

                class AutomaticCarFactory : public IFactory
                {
                    public: 
                        Car* BuildElectricCar()
                        {
                            return new ElectricCar(_nTotal, true);
                        }

                        Car* BuildDieselCar()
                        {
                            return new DieselCar(_nTotal, true);
                        }

                        Car* BuildPetrolCar()
                        {
                            return new PetrolCar(_nTotal, true);
                        }
                };

                class TestDriver
                {
                    public: 
                        void Drive()
                        {
                            std::vector<Car*> cars;

                            IFactory* manualFactory = new ManualCarFactory();
                            IFactory* automaticFactory = new ManualCarFactory();

                            // Build an electric automatic car
                            auto p1 = automaticFactory->BuildElectricCar();

                            manualFactory->BuildDieselCar();
                            
                            p1->Drive();
                        }
                };
            }
        }
    }
}
