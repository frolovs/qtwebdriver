// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "webdriver_error.h"

#include <sstream>

namespace webdriver {

namespace {

// Returns the string equivalent of the given ErrorCode.
const char* DefaultMessageForErrorCode(ErrorCode code) {
  switch (code) {
    case kSuccess:
      return "Success";
    case kNoSuchElement:
      return "The element could not be found";
    case kNoSuchFrame:
      return "The frame could not be found";
    case kUnknownCommand:
      return "Unknown command";
    case kStaleElementReference:
      return "Element reference is invalid";
    case kElementNotVisible:
      return "Element is not visible";
    case kInvalidElementState:
      return "Element is in an invalid state";
    case kUnknownError:
      return "Unknown error";
    case kElementNotSelectable:
      return "Element is not selectable";
    case kXPathLookupError:
      return "XPath lookup error";
    case kTimeout:
      return "Timed out error";
    case kNoSuchWindow:
      return "The window could not be found";
    case kInvalidCookieDomain:
      return "The cookie domain is invalid";
    case kUnableToSetCookie:
      return "Unable to set cookie";
    case kUnexpectedAlertOpen:
      return "An open modal dialog blocked the operation";
    case kNoAlertOpenError:
      return "No JavaScript modal dialog is open";
    case kScriptTimeout:
      return "Timed out waiting for asyncrhonous script";
    default:
      return "<unknown>";
  }
}

}  // namespace

Error::Error(ErrorCode code)
    : code_(code),
      details_(DefaultMessageForErrorCode(code)) {
}

Error::Error(ErrorCode code, const std::string& details)
    : code_(code), details_(details) {
}

Error::~Error() {
}

void Error::AddDetails(const std::string& details) {
    details_ = details + ";\n " + details_;
}

ErrorCode Error::code() const {
    return code_;
}

const std::string& Error::details() const {
    return details_;
}

}  // namespace webdriver
