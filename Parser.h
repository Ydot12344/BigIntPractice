#pragma once
#include <utility>
#include<vector>
#include<string>
#include<sstream>

template<typename T>
class Parser{
public:
    Parser(std::vector<std::string_view>  t) : tokens(std::move(t)){}

    Parser(std::string_view str){
        tokenize(str);
    }

    T expression(){
        T first = term();

        while(pos != tokens.size()){
            std::string_view op = tokens[pos];
            if(op != "+" && op != "-"){
                break;
            }
            else {
                pos++;
            }

            T second = term();
            if(op == "+")
                first += second;
            else
                first -= second;
        }

        return first;
    }
private:
    std::vector<std::string_view> tokens;
    int pos = 0;

    void tokenize(std::string_view str){
        int i = 0;
        int start_pos = 0;
        bool was_op = false;
        while(i < str.size()){
            if(str[i] == '(' || str[i] == ')')
                tokens.push_back(str.substr(i,1));
            else if((str[i] == '+' || str[i] == '*' || str[i] == '/' || str[i] == '%'))
                tokens.push_back(str.substr(i, 1));
            else if(str[i] == '-' && (str[i+1] > '9' || str[i+1] < '0'))
                tokens.push_back(str.substr(i, 1));
            else if(str[i] != ' ') {
                start_pos = i;
                i++;
                while (str[i] >= '0' && str[i] <= '9' && i < str.size())
                    i++;
                tokens.push_back(str.substr(start_pos, i - start_pos));
                i--;
            }
            i++;
        }


    }
    T term(){
        T first = factor();

        while(pos != tokens.size()){
            std::string_view op = tokens[pos];
            if(op != "*" && op != "/" && op != "%")
                break;
            else
                pos++;

            T second = factor();
            if(op == "*")
                first *= second;
            else if(op == "/")
                first /= second;
            else
                first %= second;
        }

        return first;
    }

    T factor(){
        std::string_view next = tokens[pos];

        T result;

        if(next == "("){
            pos++;
            result = expression();
            pos++;

            return result;
        }
        pos++;

        return T(next);
    }
};