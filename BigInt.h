#pragma once
#include<iostream>
#include<vector>

class BigInt {
public:
    BigInt();

    BigInt(int a);

    BigInt(const BigInt &other);

    BigInt(BigInt &&other) noexcept;

    BigInt(const std::string& s);

    BigInt& operator=(const BigInt& other) noexcept;

    BigInt& operator=(BigInt&& other) noexcept;

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
    std::vector<char> num;
    char sign;
};

std::istream& operator>>(std::istream& stream, BigInt& other);
std::ostream& operator<<(std::ostream& stream, const BigInt& other);
