# GudTimes
For my Software Development course at Queen's University. My team is making a calendar desktop application that will display a user's .ics calendar. Features include adding events to a calendar, removing events from a calendar, scheduling events between multiple users (time finding algorithm to avoid calendar conflict), and a notification system. By the end of the 12-week project, we were able to get all of the listed functionality complete and demo it for the class.

<h2>Motivation</h2>
For our Software Develpoment course at Queen's University (CMPE/CISC 320), we were tasked with making a program in 12 weeks. We decided to base our project on a common problem students have - being unable to schedule events or meetings due to not knowing others' availability. This is why we created GüdTimes.

<h2>Installation</h2>
We developed GüdTimes in the Code::Blocks IDE written in C++. Much of our code utilized the wxWidgets Cross-Platform GUI Library using wxFormBuilder for our main GUI and wxDateTime object for the date-time information of our events. 

<h3>Code::Blocks</h3> 
Download Website: http://www.codeblocks.org/downloads/26

<h3>GUI Setup - WxWidgets 2.8.12 on MinGW 32-bit</h3>
Process for setting up wxWidgets for CodeBlocks

1. Download wxWidgets 2.8.12 source code <a href="http://sourceforge.net/projects/wxwindows/files/2.8.12/wxMSW-2.8.12-Setup.exe/download?use_mirror=iweb">wxMSW-2.8.12-Setup.exe</a>

2. Extract to c:\wxWidgets-2.8.12

3. Open command shell (cmd.exe) and cd to c:\wxWidgets-2.8.12\build\msw

4. type PATH=c:\MinGW\bin; (change to match your MinGW install location)

5. type mingw32-make -f makefile.gcc BUILD=release SHARED=1 MONOLITHIC=1 UNICODE=0 CXXFLAGS=-fno-keep-inline-dllexport -j4

6. Wait for compilation to finish (this will take a while...)

7. Download and install <a href="http://sourceforge.net/projects/wxformbuilder/">wxFormBuilder</a>

8. Open CodeBlocks, create a new project

9. Select wxWidgets project

10. Select wxWidgets version 2.8.x

11. Give project a title

12. Select wxFormBuilder and Frame Based

13. Leave the location parameter as is and click next, in the window that appears set the base path to c:\wxWidgets-2.8.12

14. Press close, press ok on the error message

15. Press next again, set compiler to GNU GCC Compiler (will automatically find your MinGW if its in the default location)

16. Select 'Use wxWidgets DLL', 'wxWidgets is built as a monolithic library', and 'Configure Advanced Options' only

17. Press yes on the warning message

18. Make sure Use __WXDEBUG... is unselected, press Finish

19. Press Tools->Configure Tools

20. Click add, Name = wxFormBuilder, Executable = Path to where you installed wxFormBuilder.exe, Working Directory = $(PROJECT_DIR)

21. Click Ok on both windows.

22. Add libraries as needed by right clicking project and selecting build options, adding .a files to linker settings, adding include (.h) directories to search directories->Compiler, and adding library directory to search directories->Linker (e.g. libssh)
