/**
 * @file CalculatorServiceImpl.h
 * @brief 计算器服务的具体实现
 * 
 * 提供CalculatorService接口的标准实现，包含基本四则运算的具体逻辑
 * 作为RPC框架中服务实现的示例
 */
#ifndef CALCULATOR_SERVICE_IMPL_H
#define CALCULATOR_SERVICE_IMPL_H

#include "CalculatorService.h"

/**
 * @class CalculatorServiceImpl
 * @brief 计算器服务接口的具体实现类
 * 
 * 继承自CalculatorService接口，实现了基本的四则运算功能
 * 提供了RPC服务的实际业务逻辑处理
 */
class CalculatorServiceImpl : public CalculatorService {
public:
    /**
     * @brief 加法运算实现
     * 
     * 计算两个整数的和
     * @param a 第一个操作数
     * @param b 第二个操作数
     * @return 两个数的和
     */
    long long add(long long a, long long b) override {
        return a + b;
    }
    
    /**
     * @brief 减法运算实现
     * 
     * 计算两个整数的差
     * @param a 被减数
     * @param b 减数
     * @return 两个数的差
     */
    long long subtract(long long a, long long b) override {
        return a - b;
    }
    
    /**
     * @brief 乘法运算实现
     * 
     * 计算两个整数的乘积
     * @param a 第一个因数
     * @param b 第二个因数
     * @return 两个数的乘积
     */
    long long multiply(long long a, long long b) override {
        return a * b;
    }
    
    /**
     * @brief 除法运算实现
     * 
     * 计算两个数的商，包含除以零检查
     * @param a 被除数
     * @param b 除数
     * @return 两个数的商，以double类型返回确保精度
     * @throw std::runtime_error 当除数为零时抛出异常
     */
    double divide(long long a, long long b) override {
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        return static_cast<double>(a) / b;
    }
};

#endif // CALCULATOR_SERVICE_IMPL_H