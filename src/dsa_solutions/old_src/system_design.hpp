#include <iostream>
#include <list>
#include <unordered_map>

namespace SystemDesign
{
    template <typename T>
    class CacheItem
    {
    private:
        const size_t _nSize;
        uint _nKey;
        const T& _tRefValue;
        CacheItem* _pPrev;
        CacheItem* _pNext;
        
        // For new items associated to this only
        CacheItem(  const uint& key, 
                    const T& refValue, 
                    CacheItem* prev, 
                    CacheItem* next) : _nKey(key), _tRefValue(refValue), _pPrev(prev), _pNext(next)
        { }

        // Search the item with the corresponding key
        // @private
        // @return CacheItem*
        CacheItem* _search(const uint& key, CacheItem* pItem)
        {
            if (pItem)
                if (pItem->_nKey == key)
                    return pItem;
                else
                    return _search(key, pItem->_pNext);
            else
                return nullptr;
        }

        void _detach(const bool bPushFront = false)
        {
            if (bPushFront)
            {
                if(_pPrev)
                {
                    _pPrev->_pNext = this->_pNext;
                    if(this->_pNext)
                    {
                        this->_pNext->_pPrev = _pPrev;
                        this->_pNext = nullptr;
                    }
                    _pPrev = nullptr;
                }
            }
            else
            {
                if(_pPrev)
                {
                    _pPrev->_pNext = this->_pNext;
                    if(this->_pNext)
                    {
                        this->_pNext->_pPrev = _pPrev;
                        this->_pNext = nullptr;
                    }
                    _pPrev = nullptr;
                }

                if(this->_pNext)
                {
                    this->_pNext->_pPrev = _pPrev;
                    this->_pNext = nullptr;
                }
            }
        }

        void _pushFront(CacheItem* pItemToForward)
        {
            
        }

    public:
        CacheItem(  const size_t& size,
                    const uint& key, 
                    const T& refValue) : _nSize(size), _nKey(key), _tRefValue(refValue), _pPrev(nullptr), _pNext(nullptr)
        { }

        T& operator[](const int& key)
        {
            CacheItem* pItem = _search(key, this);
            if (pItem)
            {    
                pItem->Detach();
            }

            return -1;
        }

        void Insert(const uint& key, const T& refValue)
        {
            
        }

        bool Remove(const uint& key)
        {

        }
    };
    
    template <typename TKey, typename TData, size_t nSize = 5>
    class LRUCache
    {
    private:
        const size_t _nSize = nSize;
        CacheItem<TData> *_pListHead;

    public:
        LRUCache() = delete;
        LRUCache(const size_t& size) : _nSize (size), _pListHead(nullptr)
        { 
            std::list<TData&> _dataList;
            std::unordered_map<uint32_t, std::list<TData&>
        }
    };

    template <typename TData, size_t size = 5>
    class STL_LRUCache
    {
    private:
        typdef std::list<TData&> ;
        std::unordered_map<uint, std::list<TData&>::> 
    }
}