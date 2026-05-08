# 三层嵌套 std::tuple 运行时索引分发（核心模板版）

## 核心需求

三层嵌套 tuple（tuple → tuple → tuple → 自定义类），通过运行时参数 `id/subId/type` 索引到最底层对象，调用其统一实现的 `func1\(\)/func2\(\)/func3\(\)`，无需虚继承、多态。

支持 C\+\+17 及以上。

## 核心模板实现（仅保留关键代码）

```cpp
#include <tuple>

// 工具：单层tuple 运行时下标分发（核心工具）
template <typename Func, typename... Args>
bool tuple_dispatch_by_index(size_t index, Func&& func, std::tuple<Args...>& t)
{
    bool found = false;
    [&]<size_t... Is>(std::index_sequence<Is...>)
    {
        ((Is == index && (func(std::get<Is>(t)), found = true)), ...);
    }(std::index_sequence_for<Args...>{});
    return found;
}

// 工具：底层对象函数路由（统一调用func1/func2/func3）
template <typename Obj>
void obj_func_route(Obj& obj, int funcNo)
{
    switch (funcNo)
    {
        case 1: obj.func1(); break;
        case 2: obj.func2(); break;
        case 3: obj.func3(); break;
        default: break;
    }
}

// 对外统一入口：三层嵌套tuple分发
template <typename TripleTuple>
void triple_tuple_dispatch(TripleTuple& rootTpl, 
                           size_t id, size_t subId, size_t type, 
                           int funcNo)
{
    // 第一层（id）→ 第二层tuple
    tuple_dispatch_by_index(id, [&](auto& tplL2)
    {
        // 第二层（subId）→ 第三层tuple
        tuple_dispatch_by_index(subId, [&](auto& tplL3)
        {
            // 第三层（type）→ 底层对象，调用对应函数
            tuple_dispatch_by_index(type, [&](auto& obj)
            {
                obj_func_route(obj, funcNo);
            }, tplL3);
        }, tplL2);
    }, rootTpl);
}

```

## 核心接口说明

```cpp
template <typename TripleTuple>
void triple_tuple_dispatch(TripleTuple& rootTpl, 
                           size_t id, size_t subId, size_t type, 
                           int funcNo);
```

- `rootTpl`：三层嵌套的根 tuple（顶层 tuple）

- `id`：第一层 tuple 的运行时索引

- `subId`：第二层 tuple 的运行时索引

- `type`：第三层 tuple 的运行时索引

- `funcNo`：函数编号（1=func1，2=func2，3=func3）

## 使用约束

1. 编译器支持 C\+\+17 及以上（支持 lambda 模板、index\_sequence）；

2. 最底层所有自定义类，必须公有实现 `void func1\(\)`、`void func2\(\)`、`void func3\(\)`；

3. 索引（id/subId/type）不可越界，越界会忽略不执行。

> （注：文档部分内容可能由 AI 生成）
