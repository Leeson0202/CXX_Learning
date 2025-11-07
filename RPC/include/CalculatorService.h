/**
 * @file CalculatorService.h
 * @brief 计算器服务接口定义
 * 
 * 定义了RPC系统中计算器服务的接口，包含基本的四则运算操作
 * 作为RPC框架中的服务接口示例
 */
#ifndef CALCULATOR_SERVICE_H
#define CALCULATOR_SERVICE_H

#include <string>

/**
 * @class CalculatorService
 * @brief 计算器服务接口类
 * 
 * 提供基本的数学运算功能，作为RPC服务接口的示例实现
 * 采用纯虚函数设计，允许不同的实现类提供具体功能
 */
class CalculatorService {
public:
    /**
     * @brief 虚析构函数
     * 
     * 确保派生类能够正确析构
     */
    virtual ~CalculatorService() = default;
    
    /**
     * @brief 加法运算
     * 
     * 计算两个整数的和
     * @param a 第一个操作数
     * @param b 第二个操作数
     * @return 两个数的和
     */
    virtual long long add(long long a, long long b) = 0;
    
    /**
     * @brief 减法运算
     * 
     * 计算两个整数的差
     * @param a 被减数
     * @param b 减数
     * @return 两个数的差
     */
    virtual long long subtract(long long a, long long b) = 0;
    
    /**
     * @brief 乘法运算
     * 
     * 计算两个整数的乘积
     * @param a 第一个因数
     * @param b 第二个因数
     * @return 两个数的乘积
     */
    virtual long long multiply(long long a, long long b) = 0;
    
    /**
     * @brief 除法运算
     * 
     * 计算两个数的商
     * @param a 被除数
     * @param b 除数
     * @return 两个数的商
     * @throw std::runtime_error 当除数为零时抛出异常
     */
    virtual double divide(long long a, long long b) = 0;
};

#endif // CALCULATOR_SERVICE_H