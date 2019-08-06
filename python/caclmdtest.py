# python ./caclmdtest.py -b 3 -z 10 -I 5000 --np 8
# coding: utf-8
import sys
import argparse

__author__ = 'ypdai'    

parser = argparse.ArgumentParser()
parser.add_argument("-b", required=True, type=int, dest="branch", default=1,
                    help="branching factor of hierarchical directory structure")
parser.add_argument("-z", required=True, type=int, dest="zone", default=1,
                    help="depth of hierarchical directory structure")
parser.add_argument("-I", required=True, type=int, dest="item", default=10, help="number of items per tree node")
parser.add_argument("--np", required=True, type=int, dest="number", default=1, help=u"number of concurrent threads")

args = parser.parse_args()

n = 0
m = 1


def calc(branch, zone):
    global n, m
    if zone <= 0:
        return
    n = n + branch ** m
    m += 1
    return calc(branch, zone - 1)


calc(args.branch, args.zone)

ds = n + 2
fs = (ds - 1) * args.item

fs = fs * args.number if args.number >= 1 else fs

print("dirs: %s" % ds)
print("files: %s" % fs)
