/*
 * Copyright (C) 2008, 2009, 2013, 2014, 2015, 2016 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#pragma once

#if ENABLE(INDEXED_DATABASE_IN_WORKERS)

#include "Supplementable.h"
#include <wtf/text/WTFString.h>

namespace WebCore {

class IDBFactory;
class WorkerGlobalScope;

namespace IDBClient {
class IDBConnectionProxy;
}

class WorkerGlobalScopeIndexedDatabase : public Supplement<WorkerGlobalScope> {
public:
    explicit WorkerGlobalScopeIndexedDatabase(WorkerGlobalScope&, IDBClient::IDBConnectionProxy&);
    virtual ~WorkerGlobalScopeIndexedDatabase();

    static IDBFactory* indexedDB(WorkerGlobalScope&);

private:
    IDBFactory* indexedDB();

    static const char* supplementName();
    static WorkerGlobalScopeIndexedDatabase* from(WorkerGlobalScope&);

    RefPtr<IDBFactory> m_idbFactory;
    Ref<IDBClient::IDBConnectionProxy> m_connectionProxy;
};

} // namespace WebCore

#endif // ENABLE(INDEXED_DATABASE_IN_WORKERS)
