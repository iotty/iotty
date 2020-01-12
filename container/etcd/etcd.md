# Etcd

## Raft

- Time Sequence Required

```text
broadcastTime   <<   electionTimeout   <<    MTBF
 1.ms~10.ms           10.ms~500.ms        1.h~1.Month

broadcastTime = Network Latency + Disk Write
         MTBF = Mean Time Between Failures of Nodes
```

- Data Exchange

```text
                                                +--------+
                                                |Follower|<------+
                                                +--------+       |
                                              //                 |
                             3.1 Confirm:v=3 //                  |
                                            // 2.1 Copy:v=3      |
              4.1 Confirm:v=3              //                    |
+------+ <------------------------ +------+/                     |
|Client| ------------------------> |Leader|----------------------+ 4.2 Commit:v=3
+------+      1. Commit:v=3        +------+\                     |
                                           \\                    |
                                            \\                   |
                             3.1 Confirm:v=3 \\2.1 Copy:v=3      |
                                              \\                 |
                                                +--------+       |
                                                |Follower|<------+
                                                +--------+
```

## Etcd Server


- Architecture

```text
+-------------------------+
| +---------------------+ |
| |     HTTP LAYER      | |
| +---------------------+ |
|                         |
| +-------+ +-----------+ |
| |  RAFT | |           | |
| +-------+ | Replicate | |
| +-------+ | State     | |
| | Store | | Machine   | |
| +-------+ +-----------+ |
+-------------------------+
```

- Server Connection Topology

#.Connection = Cn^2

```text
+-------------+                 +-------------+
| ETCD-SERVER |<----------------| ETCD-SERVER |
+-------------|---------------->+-------------+
            /\\                   //\
              \\                 //
               \\               //
                \\             //
                 \\/         \//
                 +-------------+
                 | ETCD-SERVER |
                 +-------------+
```

## Cluster Initialization

- Static Configuration

- Etcd self-discovery

```bash
$ ETCD_DISCOVERY=$(curl https://discovery.etcd.io/new?size=3)
$ etcd --name etcdX
       --initial-advertise-peer-urls https://etcdX:2380
       --listen-peer-urls https://etcdX:2380
       --listen-client-urls https://etcdX:2379,https://localhost:2379
       --advertise-client-urls https://etcdX:2379
       --discovery $ETCD_DISCOVERY
```