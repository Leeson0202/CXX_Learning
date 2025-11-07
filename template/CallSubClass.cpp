#include <iostream>
#include <functional>

// 定义父类
class Parent {
public:
    // 父类的公共方法，接受一个回调函数和参数
    void processData(const std::function<void(int)>& callback) {
        std::cout << "Parent class is processing data and will call the callback." << std::endl;
        // 调用回调函数，并传递参数
        callback(m_key);
    }
private:
    int m_key = 10;
};

// 定义子类
class Child : public Parent {
public:
    // 子类调用父类的方法，并传递回调函数
    void ChildFunc1() {
        // 使用 std::bind 绑定子类的成员函数和当前对象
        auto callback = std::bind(&Child::CallFunc1, this, std::placeholders::_1);
        // 调用父类的方法，并传递回调函数和数据
        processData(callback);
    }
    // 子类调用父类的方法，并传递回调函数
    void ChildFunc2() {
        // 使用 std::bind 绑定子类的成员函数和当前对象
        auto callback = std::bind(&Child::CallFunc2, this, std::placeholders::_1);
        // 调用父类的方法，并传递回调函数和数据
        processData(callback);
    }
private:
    // 子类的回调函数，接收父类传递的参数
    void CallFunc1(int data) {
        std::cout << "CallFunc1 data: " << data << " child vlaue:"<< m_value << std::endl;
    }
    // 子类的回调函数，接收父类传递的参数
    void CallFunc2(int data) {
        std::cout << "CallFunc2 data: " << data << " child vlaue:"<< m_value << std::endl;
    }

    int m_value = 100;
};

int main() {
    Child child;
    // 调用子类的方法，触发父类调用和回调
    child.ChildFunc1();
    child.ChildFunc2();
    return 0;
}