// Copyright (c) 2013 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "atom/browser/browser.h"

#include <stdlib.h>

#include "atom/browser/native_window.h"
#include "atom/browser/window_list.h"
#include "atom/common/atom_version.h"

namespace atom {

void Browser::Focus() {
  // Focus on the first visible window.
  WindowList* list = WindowList::GetInstance();
  for (WindowList::iterator iter = list->begin(); iter != list->end(); ++iter) {
    NativeWindow* window = *iter;
    if (window->IsVisible()) {
      window->Focus(true);
      break;
    }
  }
}

void Browser::AddRecentDocument(const base::FilePath& path) {
}

std::string Browser::GetExecutableFileVersion() const {
  return ATOM_VERSION_STRING;
}

std::string Browser::GetExecutableFileProductName() const {
  return "Atom-Shell";
}

}  // namespace atom
