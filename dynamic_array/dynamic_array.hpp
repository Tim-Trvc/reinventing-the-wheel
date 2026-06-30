#pragma once

#include <vector>
#include <cassert>
#include <cstddef>
#include <cstdlib>

template <typename T>
struct DynamicArrayTable {
  std::size_t frame_size;
  std::vector<T*> frames;

  T* allocate_frame() {
    T* new_frame = (T*) std::malloc(frame_size * sizeof(T));

    if (new_frame == nullptr) {
      // TODO implement error handling
    }

    return new_frame;
  }

  void init_frames(std::size_t frame_count) {
    this->frames = {};
    for (std::size_t i=0; i<frame_count; ++i) {
      T* frame = allocate_frame();
      this->frames.push_back(frame);
    }
  }

  ~DynamicArrayTable() {
    for (auto& frame : this->frames) {
      free(frame);
    }
  }
};

template <typename T>
struct DynamicArray {
  DynamicArrayTable<T> table;

  DynamicArray(std::size_t initial_size, std::size_t frame_size) {
    table = {
      .frame_size = frame_size,
    };

    table.init_frames(5);
  }

  DynamicArray(std::size_t initial_size) : DynamicArray(initial_size, initial_size) {
  }

  ~DynamicArray() {
  }

  T& operator[](std::size_t position) {
    std::size_t frame_number = position / table.frame_size;
    std::size_t frame_position = position % table.frame_size;
    
    assert(frame_number< table.frames.size() && "Index out of bounds!"); 

    T* frame = table.frames[frame_number];
    return frame[frame_position];
  }
};
