# ADR: Use of `LayerWrapper` and `LayerHandle` for Generic Layers in `LayerStack`

## Why?

In short: to learn how to write generic code without the use of `virtual` keyword.

## The problem

I needed a way to have a generic datatype to use in `LayerStack`. I want to have a Layer system, where I render layers one by one, 
and propagate event to the layers. To achieve this, I need to make sure the Layers have required methods implemented. 

## The solution

`LayerHandle` is a type-erased wrapper that stores function pointers to the `Layer`'s relevant methods (e.g., `OnAttach`, `OnUpdate`, `OnEvent`), 
which are statically populated through a templated `LayerWrapper`. This enables runtime dispatch without virtual functions.

## The alternative

Alternatively, each `Layer` could have a static `type` identifier and we could store them in a container using raw or smart pointers. 
At runtime, we would downcast with `static_cast` to the concrete type before invoking methods. 
However, this approach is error-prone, less type-safe, and makes generic usage harder. 
It also doesn't scale well if we want `LayerStack` to be fully generic and unaware of specific layer types.
