#include<iostream>
using namespace std;
//模拟实现vector类，并完成测试
namespace bit
{
    template<class T> 
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;
        iterator begin()
        {
            return _start;
        }
        iterator end()
        {
            return _finsh;
        }

        const_iterator cbegin() const
        {
            return _start;
        }
        const_iterator cend() const
        {
            return _finsh;
        }
        // construct and destroy

        vector()
        {
        }


        vector(int n, const T& value = T())
        {
            resize(n,val);

        }
        template<class InputIterator>

        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        vector(const vector<T>& v)
        {
            reserve(v.capacity());
            for (const auto& ch : v)
            {
                push_back(ch);
            }
        }

        vector<T>& operator= (vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            if (_start)
            {
                delete[] _start;
                _start = _finish = _endofstorage = nullptr;
            }
        }

            // capacity

            const size_t size() const
            {
                return _finsh - _start;
            }

            const size_t capacity() const
            {
                return _endofstorage - _start;
            }

            void reserve(size_t n)
            {
                if (n > capacity())
                {
                    size_t old = size();
                    T* tmp = new T[n];
                    if (_start)
                    {
                        for (size_t i = 0; i < old; i++)
                        {
                            tmp[i] = _start[i];
                        }
                        delete[] _start;
                    }
                    _start = tmp;
                    _finish = _start + old;
                    _endofstorage = _start + n;
                }
            }

            void resize(size_t n, const T& value = T())
            {
                if (n > size())
                {
                    reserve(n);
                    while (_finish < _start + n)
                    {
                        *finish = val;
                        ++finish;
                    }
                }
                else
                {
                    _finish = _start + n;
                }
            }



            ///////////////access///////////////////////////////

            T& operator[](size_t pos)
            {
                assert(pos < size());
                return _start[pos];
            }

            const T& operator[](size_t pos)const
            {
                assert(pos < size());
                return _start[pos];
            }



            ///////////////modify/////////////////////////////

            void push_back(const T& x)
            {
                if (_finish == _endofstorage)
                {
                    size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
                    reserve(newcapacity);
                }

                *_finish = x;
                ++_finish;
            }

            void pop_back()
            {
                assert(size() > 0);
                --_finish;
            }

            void swap(vector<T>& v)
            {
                std::swap(_start, v._start);
                std::swap(_finish, v._finish);
                std::swap(_endofstorage, v._endofstorage);
            }

            iterator insert(iterator pos, const T& x)
            {
                assert(pos >= _start && pos <= _finish);

                if (_finish == _endofstorage)
                {
                    size_t len = pos - _start;
                    reserve(capacity() == 0 ? 4 : capacity() * 2);
                    pos = _start + len;
                }

                iterator end = _finish - 1;
                while (end >= pos)
                {
                    *(end + 1) = *end;
                    --end;
                }

                *pos = x;

                ++_finish;

                return pos;
            }

            iterator erase(Iterator pos)
            {
                assert(pos >= _start);
                assert(pos < _finish);
                iterator it = pos + 1;
                while (it < _finish)
                {
                    *(it - 1) = *it;
                    ++it;
                }
                _finish--;

                return pos;
            }

    private:
        iterator _start = nullptr;// 指向数据块的开始
        iterator _finish = nullptr; // 指向有效数据的尾
        iterator _endofstorage = nullptr; // 指向存储容量的尾

    };

}