**COD EC HAL Template**

# HAL-Template

## 简介

* 开发工具：keil V5.38a，VsCode
* 软件环境：Window11
* 硬件环境：大疆RoboMaster开发板C型(STM32F407IGHX)
* 编译工具：Arm Compiler V5.06u7，C/C++编译

## 目录结构

```
HAL-Template
  ├───Application/API
  ├───Application/Tasks
  ├───BSP
  ├───Components/Algorithm
  ├───Components/Controller
  ├───Components/Device
  ├───Core
  ├───Docs
  ├───Drivers
  ├───MDK-ARM
  ├───Middlewares
  ├───Third_Party
  └───USB_DEVICE
```

## 模块功能说明

### IMU 惯性测量单元

* 模块参考[哈尔滨工程大学创梦之翼战队惯导姿态解算项目](https://github.com/WangHongxi2001/RoboMaster-C-Board-INS-Example)
* 详情见[Quaternion](./Docs/Quaternion.pdf)

适配常见问题：

1. STM32CubeMX添加DSP库
      1. 点击[Software Packs]/[Select Components]，在弹出的[Software Packs Component Selector]窗口中，勾选[STMicroelectronics.X-CUBE-ALGOBUILD]/[DSP Library Library]/[DSP Library 1.3.0];
      2. 关闭[Software Packs Component Selector]窗口，在[Middle and Software Packs]/[X-CUBE-ALGOBUILD]栏勾选[DSP Library Library]；
      3. 此时在工程中默认添加的LIB文件为arm_cortexM4l_math.lib(Little endian on Cortex-M4)，而实际需求为arm_cortexM4lf_math.lib (Little endian and Floating Point Unit on Cortex-M4)，后者支持浮点单元。
2. malloc函数内存申请失败
在startup_stm32f407xx.s中分配的堆空间只有0x0200个字节，而在初始化扩展卡尔曼时所申请的空间超过了0x0200，需要在该文件中修改Heap_Size以达到使用需求。

## 贡献

* 完善项目过程中，请尽量遵循以下设计原则和规范：
  * `API` 应用接口层对应应用接口，是一类功能的抽象，请不要在该层相关文件中定义实体变量；该层调用各组件层以实现功能；
  * `Bsp` 板级支持包面向底层组件，是唯一允许直接出现STM32HAL库函数的代码层；
  * 请不要跨层调用；
  * 请注意`代码规范`，建议参考[Google C++风格指南](https://zh-google-styleguide.readthedocs.io/en/latest/google-cpp-styleguide/contents/#).

* 欢迎提交Issues和Pull Requests帮助我们改进.