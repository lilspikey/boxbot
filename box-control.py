#!/usr/bin/env python

import curses
import serial
from serial.tools.list_ports import comports

def pick_port_name():
    ports = comports()
    for i, port in enumerate(ports):
        print '%d) %s (%s)' % (i+1, port[0], port[1])
    while True:
        choice = raw_input('Choose serial port: ')
        try:
            choice = int(choice) - 1
            if 0 <= choice < len(ports):
                return ports[choice][0]
        except ValueError:
            continue


def run_curses(stdscr, portname):
    port = serial.Serial(portname, baudrate=9600, timeout=0)
    lastline = ''
    try:
        stdscr.nodelay(1)
        curses.init_pair(1, curses.COLOR_WHITE, curses.COLOR_BLACK)
        stdscr.erase()
        stdscr.addstr(0,0, "BOX BOT CONTROL (%s)" % portname, curses.color_pair(1))
        stdscr.addstr(1,0, " FORWARD  = W  ", curses.color_pair(1))
        stdscr.addstr(2,0, " BACKWARD = S  ", curses.color_pair(1))
        stdscr.addstr(3,0, " LEFT     = A  ", curses.color_pair(1))
        stdscr.addstr(4,0, " RIGHT    = D  ", curses.color_pair(1))
        stdscr.addstr(5,0, " STOP     = .  ", curses.color_pair(1))
        stdscr.addstr(6,0, " QUIT     = ESC", curses.color_pair(1))
    
        while True:
            c = stdscr.getch()
            if c == 27: # possible Escape key
                if stdscr.getch() == -1:
                    break
            elif c > 0:
                port.write(chr(c))
            else:
                curses.napms(10)

            # try to read line from serial port
            # without blocking
            # we can then show line as feedback from robot
            line = []
            while port.inWaiting():
                line.append(port.read())
                if not port.inWaiting():
                    curses.napms(10)
            if line:
                line = ''.join(line).strip()
                if line:
                    lastline = line
            stdscr.addstr(7, 0, lastline.ljust(10), curses.color_pair(1))
            stdscr.refresh()
        port.write('.') # send stop command
    finally:
        port.close()


def main():
    portname = pick_port_name()
    curses.wrapper(run_curses, portname)


if __name__ == '__main__':
    main()
