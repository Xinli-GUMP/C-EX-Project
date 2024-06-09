#include <iostream>
#include <sstream>

int main()
{
    int n;

    std::istringstream in;  // 也可以使用 in("1 2")
    in.str("1 2");
    in >> n;
    std::cout << "从 \"1 2\" 读取第一个 int 后，该 int 是 " << n
              << "，str() = \"" << in.str() << "\"\n";

    std::ostringstream out("1 2");
    out << 3;
    std::cout << "将 int '3' 写入输出流 \"1 2\" 后" << "，str() = \""
              << out.str() << "\"\n";

    std::ostringstream ate("1 2", std::ios_base::ate);
    ate << 3;
    std::cout << "将 int '3' 写入后附流 \"1 2\" 后" << "，str() = \""
              << ate.str() << "\"\n";
}