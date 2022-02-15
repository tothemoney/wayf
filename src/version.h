// Copyright (c) 2012 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
#ifndef BITCOIN_VERSION_H
#define BITCOIN_VERSION_H

#include "clientversion.h"
#include <stdint.h>
#include <string>
#include <set>

//
// client versioning
//

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;

//
// database format versioning
//
static const int DATABASE_VERSION = 70509;

// hard cutoff time for CFM legacy network connections
static const int64_t CFM_LEGACY_CUTOFF = 1644624000; // Temporary: 2022-02-10 00:00:00 GMT
//static const int64_t CFM_LEGACY_CUTOFF = 1645228555; // 2022-02-18 23:55:55 GMT
static const int CFM_MIN_BLOCK_VERSION = 8;

//
// network protocol versioning
//
static const int PROTOCOL_VERSION = 62013;

// intial proto version, to be increased after version/verack negotiation
static const int INIT_PROTO_VERSION = 209;

// disconnect from peers older than this proto version
static const int MIN_PEER_PROTO_VERSION = 62011;
static const int MIN_PEER_PROTO_VERSION_CFM = 62013; // Checked
static const std::set<int> PRE_CUTOFF_VERSIONS_ALLOWED {62012}; // TODO: Remove after full cutoff

// minimum peer version accepted by DarkSendPool
static const int MIN_POOL_PEER_PROTO_VERSION = 62005;
static const int MIN_INSTANTX_PROTO_VERSION = 62005;
static const int MIN_POOL_PEER_PROTO_VERSION_CFM = 62013;
//#define MIN_POOL_PEER_MACRO pindexBest->GetBlockTime() > CFM_LEGACY_CUTOFF ? MIN_POOL_PEER_PROTO_VERSION_CFM : MIN_POOL_PEER_PROTO_VERSION
#define MIN_POOL_PEER_MACRO MIN_POOL_PEER_PROTO_VERSION
static const int MIN_INSTANTX_PROTO_VERSION_CFM = 62013;

// minimum peer version that can receive masternode payments
// V1 - Last protocol version before update
// V2 - Newest protocol version
static const int MIN_MASTERNODE_PAYMENT_PROTO_VERSION_1 = 62005;
static const int MIN_MASTERNODE_PAYMENT_PROTO_VERSION_2 = 62005;
static const int MIN_MASTERNODE_PAYMENT_PROTO_VERSION_1_CFM = 62013; // Checked
static const int MIN_MASTERNODE_PAYMENT_PROTO_VERSION_2_CFM = 62013; // Checked

// nTime field added to CAddress, starting with this version;
// if possible, avoid requesting addresses nodes older than this
static const int CADDR_TIME_VERSION = 31402;

// only request blocks from nodes outside this range of versions
static const int NOBLKS_VERSION_START = 0;
static const int NOBLKS_VERSION_END = 62004;
static const int NOBLKS_VERSION_END_CFM = 62013; // Checked

// hard cutoff time for legacy network connections
static const int64_t HRD_LEGACY_CUTOFF = 1585267200; // OFF (NOT TOGGLED)

// hard cutoff time for future network connections
static const int64_t HRD_FUTURE_CUTOFF = 9993058800; // OFF (NOT TOGGLED)

// BIP 0031, pong message, is enabled for all versions AFTER this one
static const int BIP0031_VERSION = 60000;

// "mempool" command, enhanced "getdata" behavior starts with this version:
static const int MEMPOOL_GD_VERSION = 60002;

#endif
