// Copyright 2020 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
import {formatBytes} from '../helper.mjs';

import {LogEntry} from './log.mjs';

export class DeoptLogEntry extends LogEntry {
  constructor(
      type, time, entry, deoptReason, deoptLocation, scriptOffset,
      instructionStart, codeSize, inliningId) {
    super(type, time);
    this._entry = entry;
    this._reason = deoptReason;
    this._location = deoptLocation;
    this._scriptOffset = scriptOffset;
    this._instructionStart = instructionStart;
    this._codeSize = codeSize;
    this._inliningId = inliningId;
    this.fileSourcePosition = undefined;
  }

  get reason() {
    return this._reason;
  }

  get location() {
    return this._location;
  }

  get entry() {
    return this._entry;
  }

  get functionName() {
    return this._entry.functionName;
  }

  static get propertyNames() {
    return [
      'type', 'reason', 'functionName', 'sourcePosition',
      'functionSourcePosition', 'script'
    ];
  }
}

export class CodeLogEntry extends LogEntry {
  constructor(type, time, kindName, kind, entry) {
    super(type, time);
    this._kind = kind;
    this._kindName = kindName;
    this._entry = entry;
  }

  get kind() {
    return this._kind;
  }

  get kindName() {
    return this._kindName;
  }

  get entry() {
    return this._entry;
  }

  get functionName() {
    return this._entry.functionName;
  }

  get size() {
    return this._entry.size;
  }

  get source() {
    return this._entry?.getSourceCode() ?? '';
  }

  get code() {
    return this._entry?.source?.disassemble;
  }

  toString() {
    return `Code(${this.type})`;
  }

  get toolTipDict() {
    const dict = super.toolTipDict;
    dict.size = formatBytes(dict.size);
    return dict;
  }

  static get propertyNames() {
    return [
      'type', 'kind', 'kindName', 'size', 'functionName', 'sourcePosition',
      'script', 'source', 'code'
    ];
  }
}
