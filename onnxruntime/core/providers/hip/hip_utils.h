// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

// for things shared between nvcc and onnxruntime
// as currently nvcc cannot compile all onnxruntime headers

#pragma once
#include <memory>
#include <vector>

#include "core/providers/hip/fast_divmod.h"

namespace onnxruntime {
namespace hip {

enum class SimpleBroadcast : int32_t {
  NoBroadcast = (int32_t)-1,
  LeftScalar = (int32_t)-2,
  RightScalar = (int32_t)-3,
  RightPerChannelBatch1 = (int32_t)-4,
  RightPerChannelBatchN = (int32_t)-5,
};

template <typename T>
void Fill(T* output, T value, int64_t count);

constexpr int32_t MAX_ARRAY_SIZE = 8;
template <typename T>
struct TArray {
  TArray() {
    size_ = 0;
    memset(data_, 0, sizeof(data_));
  }

  TArray(int32_t size) {
    size_ = size;
    memset(data_, 0, sizeof(data_));
  }

  T data_[MAX_ARRAY_SIZE];
  int32_t size_;
};

}  // namespace hip
}  // namespace onnxruntime
