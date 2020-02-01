//===----------------------------------------------------------------------===//
//
//                         BusTub
//
// clock_replacer.cpp
//
// Identification: src/buffer/clock_replacer.cpp
//
// Copyright (c) 2015-2019, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#include "buffer/clock_replacer.h"

namespace bustub {

ClockReplacer::ClockReplacer(size_t num_pages) {
    pages = new frame_id_t[num_pages];
    num_pages_ = num_pages;
    current_ = 0;
}

ClockReplacer::~ClockReplacer() {
    delete[] pages;
};

bool ClockReplacer::Victim(frame_id_t *frame_id) {
    return false;
}

void ClockReplacer::Pin(frame_id_t frame_id) {
    pages[frame_id]++;
}

void ClockReplacer::Unpin(frame_id_t frame_id) {
    if(pages[frame_id] > 0) {
        pages[frame_id]--;
    }
}

size_t ClockReplacer::Size() { return pages.size(); }

}  // namespace bustub
