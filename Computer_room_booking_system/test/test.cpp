
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// 将字符串转换为十六进制
auto stringToHex(const std::string &input) -> std::string
{
    std::stringstream hexStream;
    hexStream << std::hex;  //<< std::setfill('0');
    for (unsigned char c : input)
    {
        hexStream << std::setw(2) << static_cast< int >(c);
    }
    return hexStream.str();
}

// 将十六进制字符串转换回原始字符串
auto hexToString(const std::string &hexInput) -> std::string
{
    std::string output;
    if (hexInput.length() % 2 != 0)
    {
        // 十六进制输入应该是偶数长度
        throw std::runtime_error("Invalid input length for hex string.");
    }
    size_t len = hexInput.length();

    for (size_t i = 0; i < len; i += 2)
    {
        std::string byteString = hexInput.substr(i, 2);
        char byte = static_cast< char >(std::stoi(byteString, nullptr, 16));
        output.push_back(byte);
    }

    return output;
}

int main()
{
    std::string str = "Alice123";

    // 转换为十六进制
    std::string hexStr = stringToHex(str);
    std::cout << "Hexadecimal: " << hexStr << std::endl;

    // 从十六进制转换回原始字符串
    std::string originalStr = hexToString(hexStr);
    std::cout << "Original: " << originalStr << std::endl;

    return 0;
}