#pragma once
#include<iostream>
#include<vector>

class BigInt {
public:
    class divided_by_zero : std::exception{};
    BigInt();

    BigInt(int64_t a);

    BigInt(uint64_t a);

    template<typename T, typename std::enable_if<std::is_integral<T>::value, bool>::type = true>
    BigInt(T a) : BigInt(static_cast<typename std::conditional<std::is_unsigned<T>::value,uint64_t,int64_t>::type>(a)) {};

    BigInt(const std::string& s);

    BigInt(const BigInt &other);

    BigInt(BigInt &&other) noexcept;

    BigInt& operator=(const BigInt& other) & noexcept;

    BigInt& operator=(BigInt&& other) & noexcept;

    bool operator<(const BigInt &other) const noexcept;

    bool operator>(const BigInt &other) const noexcept;

    bool operator<=(const BigInt &other) const noexcept;

    bool operator>=(const BigInt &other) const noexcept;

    bool operator==(const BigInt &other) const noexcept;

    bool operator!=(const BigInt &other) const noexcept;

    BigInt &operator+=(const BigInt &other);

    BigInt &operator-=(const BigInt &other);

    BigInt operator+(const BigInt &other) const;

    BigInt operator-(const BigInt &other) const;

    BigInt operator-() const;

    BigInt& operator*= (const BigInt& other);
    BigInt  operator*  (const BigInt& other) const;

    BigInt& operator/= (const BigInt& other);
    BigInt  operator/  (const BigInt& other) const;

    BigInt& operator%= (const BigInt& other);
    BigInt  operator%  (const BigInt& other) const;

    friend std::istream& operator>>(std::istream& stream, BigInt& other);
    friend std::ostream& operator<<(std::ostream& stream, const BigInt& other);

private:
    std::vector<char> num;
    char sign;
};

std::istream& operator>>(std::istream& stream, BigInt& other);
std::ostream& operator<<(std::ostream& stream, const BigInt& other);
