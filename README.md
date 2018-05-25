# NIMSDK SDK

## 概述

[网易云信](http://netease.im)是由网易发布的一款 `IM` 云服务产品。此仓库是云信 `iOS SDK` 和 `macOS SDK` 的发布仓库。

## SDK 结构

`NIM iOS SDK` 包含 `IM` 和 `AVChat`(音视频) 两大模块。

`NIM macOS SDK` 仅包含 `IM` 模块。

具体结构为

* 云信 SDK
  * NIMSDK （IM 模块)
  
    * Libs (依赖第三方库)
    * NIMSDK.framework (静态库文件)
	
  * NIMAVChat （音视频模块）
  
    * Libs (依赖第三方库)
    * NIMAVChat.framework (静态库文件)

你可以根据需求进行选择下载。

## 集成

`NIM iOS SDK` 提供手动集成和通过 `CocoaPods` 集成两种方式，而 `NIM macOS SDK` 仅提供手动集成的方式。

### 手动集成

你可以通过[官网下载地址](http://netease.im/im-sdk-demo)下载最新版本，并添加到工程中，具体步骤参考[集成文档](http://dev.netease.im/docs/product/IM%E5%8D%B3%E6%97%B6%E9%80%9A%E8%AE%AF/SDK%E5%BC%80%E5%8F%91%E9%9B%86%E6%88%90/iOS%E5%BC%80%E5%8F%91%E9%9B%86%E6%88%90)。


### 通过 CocoaPods 集成

* iOS IM + AVChat : 使用 `pod NIMSDK` 集成
* iOS IM only : 使用 `pod NIMSDK_LITE` 集成


## 第三方依赖说明

众所周知，`iOS` 仅支持静态库 (iOS 8 之前)，这导致开发者在集成各种第三方库和 `SDK` 时常常会碰到符号文件冲突的问题，因为不同的第三方库 和 `SDK` 常常会依赖相同的库，如几乎所有和安全相关的库都会依赖 `openssl`。云信为了最大程度地方便上层开发，一方面会尽量避免引入不需要的第三方库，另一方面也会对一些第三方库进行重命名以保证不出现符号文件冲突的问题。但是由于某些库的特殊性，我们仍不得不原原本本地引入，无法做完整的修改。一种规避的方法是双方同时依赖同一份底层库代码。

举个例子，在同时使用云信和支付宝 `SDK` 时，会发生符号文件冲突的问题，原因是它们都依赖 `openssl`。在手动集成时，我们推荐直接移除某一方所依赖的 `libssl.a` 和 `libscrypto.a` 文件。而在使用 `Cocoapods` 集成时则可以通过 [post_install](https://guides.cocoapods.org/syntax/podfile.html#post_install) 方法进行冲突静态库的去除。

**在 5.1.0 后，云信 iOS 将以动态库的形式进行发布**


## 历史版本

你可以在当前仓库的 [Release](https://github.com/netease-im/NIM_iOS_SDK/releases) 进行历史版本下载。
