#ifndef LIBCLANGEX_CXSTRINGEX_H
#define LIBCLANGEX_CXSTRINGEX_H

#include "clang-c/CXString.h"
#include "llvm/ADT/StringRef.h"
// the following two functions are not exported from libclang, so copied and
// tweaked here as a workaround.

//===- CXString.cpp - Routines for manipulating CXStrings -----------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

CXString createDup(llvm::StringRef String) {
  CXString Result;
  char *Spelling = static_cast<char *>(llvm::safe_malloc(String.size() + 1));
  memmove(Spelling, String.data(), String.size());
  Spelling[String.size()] = 0;
  Result.data = Spelling;
  Result.private_flags = (unsigned)/* CXS_Malloc */ 1;
  return Result;
}

CXString createRef(llvm::StringRef String) {
  // If the string is not nul-terminated, we have to make a copy.

  // FIXME: This is doing a one past end read, and should be removed! For memory
  // we don't manage, the API string can become unterminated at any time outside
  // our control.

  if (!String.empty() && String.data()[String.size()] != 0)
    return createDup(String);

  CXString Result;
  Result.data = String.data();
  Result.private_flags = (unsigned)/* CXS_Unmanaged */ 0;
  return Result;
}

#endif
