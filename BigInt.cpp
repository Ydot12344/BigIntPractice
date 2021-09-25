#include "BigInt.h"

BigInt::BigInt() : sign(1) {
    num.push_back(0);
}

BigInt &BigInt::operator=(BigInt &&other) & noexcept {
    sign = other.sign;
    num = std::move(other.num);
    return *this;
}

BigInt &BigInt::operator=(const BigInt &other) & noexcept {
    sign = other.sign;
    num = other.num;
    return *this;
}

BigInt::BigInt(const std::string &s) {
    sign = s[0] == '-' ? -1 : 1;
    for(int i = s.size()-1; i >= (2 + sign)%3; --i) {
        num.push_back(s[i] - '0');
    }
    if(num.size() == 1 && num[0] == 0) sign =1;
}

BigInt::BigInt(int a) : sign(a < 0 ? -1 : 1){
    a = std::abs(a);
    if(a == 0)
        num.push_back(0);
    while(a != 0){
        num.push_back(a%10);
        a/=10;
    }
}
BigInt::BigInt(BigInt &&other)  noexcept : sign(other.sign), num(std::move(other.num)){}
BigInt::BigInt(const BigInt &other) : sign(other.sign), num(other.num){}

bool BigInt::operator<(const BigInt &other) const noexcept {
    if(sign != other.sign)
        return sign < other.sign;
    else if(num.size() != other.num.size()){
        return sign == -1 ? num.size() > other.num.size() : num.size() < other.num.size();
    }
    else{
        int i = num.size()-1;
        while(i >= 0 && num[i] == other.num[i])i--;

        return i != -1 && (sign == 1 ? num[i] < other.num[i] : num[i] > other.num[i]);
    }
}

bool BigInt::operator>(const BigInt &other) const noexcept {
    return other < *this;
}

bool BigInt::operator<=(const BigInt &other) const noexcept {
    return !(*this > other);
}

bool BigInt::operator>=(const BigInt &other) const noexcept {
    return !(*this < other);
}

bool BigInt::operator==(const BigInt &other) const noexcept {
    return *this <= other && *this >= other;
}

bool BigInt::operator!=(const BigInt &other) const noexcept {
    return !(*this == other);
}

BigInt BigInt::operator-() const {
    BigInt tmp = *this;
    tmp.sign*=-1;
    return tmp;
}

BigInt &BigInt::operator+=(const BigInt &other) {
    int dop = 0;
    int tmp;
    if(sign * other.sign > 0) {
        if (num.size() < other.num.size()) num.resize(other.num.size());
        for (int i = 0; i < num.size(); i++) {
            if (i < other.num.size()) {
                tmp = (num[i] + other.num[i] + dop) % 10;
                dop = (num[i] + other.num[i] + dop) / 10;
                num[i] = tmp;
            } else {
                tmp = (num[i] + dop) % 10;
                dop = (num[i] + dop) / 10;
                num[i] = tmp;
            }
        }
        if (dop != 0)
            num.push_back(dop);
        return *this;
    }
    else{
        int fl = 0;
        if(this->sign == -1)
            fl = -*this < other;
        else
            fl = *this < -other;
        fl = fl*2 - 1;
        if (num.size() < other.num.size()) num.resize(other.num.size());
        for(int i = 0; i < num.size(); i++){
            if(i < other.num.size()){
                tmp = (10 + fl*other.num[i] + -fl*num[i] - dop) % 10;
                dop = fl*other.num[i] + -fl*num[i] - dop < 0 ? 1 : 0;
                num[i] = tmp;
            }
            else{
                tmp = (10 + num[i] - dop)%10;
                dop =  num[i] - dop < 0 ? 1 : 0;
                num[i] = tmp;
            }
        }

        fl++;
        while(num.size() > 1 && num.back() == 0) num.pop_back();

        if(fl) sign*=-1;

        if(num.size() == 1 && num[0] == 0)
            sign = 1;

        return *this;
    }
}

BigInt BigInt::operator+(const BigInt &other) const {
    BigInt tmp = *this;
    return tmp += other;
}

BigInt &BigInt::operator-=(const BigInt &other) {
    return *this += -other;
}

BigInt BigInt::operator-(const BigInt &other) const {
    BigInt tmp = *this;
    return tmp -= other;
}

BigInt BigInt::operator*(const BigInt &other) const {
    BigInt tmp = *this;
    return tmp *= other;
}

BigInt& BigInt::operator*=(const BigInt &other) {
    if(other == BigInt(0) || *this == BigInt(0)){
        *this = 0;
        this->sign = 1;
        return *this;
    }

    BigInt res = 0;
    BigInt tmp = 0;
    char res_sign = other.sign * sign;

    for(int i = 0; i < other.num.size(); ++i){
        tmp.num.clear();
        for(int j = 0; j < i; ++j)
            tmp.num.push_back(0);

        int dop = 0;
        int tmp_num = 0;
        for(char j : this->num){
            tmp_num = (j * other.num[i]  + dop) % 10;
            dop = (j * other.num[i]  + dop) / 10;
            tmp.num.push_back(tmp_num);
        }
        if(dop != 0)
            tmp.num.push_back(dop);

        res += tmp;
    }

    *this = std::move(res);
    this->sign = res_sign;
    return *this;
}

std::istream& operator>>(std::istream& stream, BigInt& other){
    std::string s;
    stream >> s;
    other.num.clear();
    other.sign = s[0] == '-' ? -1 : 1;
    for(int i = s.size()-1; i >= (2 + other.sign) % 3; --i){
        other.num.push_back(s[i] - '0');
    }
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const BigInt& other){
    if(other.sign == -1)
        stream << "-";
    for(int i = other.num.size()-1; i >=0; --i)
        stream << (int)(other.num[i]);
    return stream;
}