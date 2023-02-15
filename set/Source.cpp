#include <iostream>
#include <algorithm>
#include <set>

class SetOfIntegers
{

public:

    SetOfIntegers() {}
	SetOfIntegers(std::set<int>_list) : elements_{ _list } {}

    bool contains(int value)
    {
        return std::find(elements_.begin(), elements_.end(), value) != elements_.end();
    }

    void insert(int value)
    {
        if (!contains(value))
            elements_.insert(value);
    }
    
    //сложение множеств
    friend SetOfIntegers operator+(const SetOfIntegers& temp1, const SetOfIntegers& temp2)
    {
        SetOfIntegers result(temp1);
        for (int value : temp2.elements_)
            result.insert(value);
        return result;
    }

    //только не общие
    friend SetOfIntegers operator-(const SetOfIntegers& temp1, const SetOfIntegers& temp2)
    {
        SetOfIntegers result(temp1);
        for (int value : temp2.elements_)
            result.elements_.erase(value);
        return result;
    }
    
    //только общие
    SetOfIntegers operator*(SetOfIntegers& other)
    {
        SetOfIntegers result;
        for (int value : elements_)
            if (other.contains(value))
                result.insert(value);
        return result;
    }

    SetOfIntegers& operator+=(const SetOfIntegers& other)
    {
        for (int value : other.elements_)
            insert(value);
        return *this;
    }

    SetOfIntegers& operator-=(const SetOfIntegers& other)
    {
        for (int value : other.elements_)
            elements_.erase(value);
        return *this;
    }

    SetOfIntegers& operator*=(SetOfIntegers& other)
    {
        SetOfIntegers result;
        for (int value : elements_)
            if (other.contains(value))
                result.insert(value);
        elements_ = result.elements_;
        return *this;
    }

    SetOfIntegers& operator=(const SetOfIntegers& other)
    {
        elements_ = other.elements_;
        return *this;
    }
    
    //операторы сравления по размеру
    bool operator==(const SetOfIntegers& other) const
    {
        return (elements_.size() == other.elements_.size());
    }
    bool operator!=(const SetOfIntegers& other) const
    {
        return (elements_.size() != other.elements_.size());
    }
    bool operator>(const SetOfIntegers& other) const
    {
        return (elements_.size() > other.elements_.size());
    }
    bool operator<(const SetOfIntegers& other) const
    {
        return(elements_.size() < other.elements_.size());
    }
    bool operator>=(const SetOfIntegers& other) const
    {
        return (elements_.size() >= other.elements_.size());
    }
    bool operator<=(const SetOfIntegers& other) const
    {
        return (elements_.size() <= other.elements_.size());
    }

    void print()
    {
        for (auto item : elements_)
            std::cout << item << " ";
        std::cout << std::endl;
    }

protected:
	std::set<int>elements_;
};

int main()
{
    std::set<int>con1{ 1,2,4,5 };
    std::set<int>con2{ 1,3,5,7 };
    SetOfIntegers set1(con1);
    SetOfIntegers set2(con2);
    std::cout << (set1 == set2) << std::endl;
    set1 *= set2;
    set1.print();
	return 0;
}