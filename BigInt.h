#pragma once
#include<iostream>
#include<vector>

class BigInt {
public:
    BigInt();

    BigInt(int a);

    BigInt(const BigInt &other);

    BigInt(BigInt &&other);

    BigInt(const std::string& s);

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

    friend std::istream& operator>>(std::istream& stream, BigInt& other);
    friend std::ostream& operator<<(std::ostream& stream, const BigInt& other);

private:
    char sign;
    std::vector<char> num;
};

std::istream& operator>>(std::istream& stream, BigInt& other);
std::ostream& operator<<(std::ostream& stream, const BigInt& other);
