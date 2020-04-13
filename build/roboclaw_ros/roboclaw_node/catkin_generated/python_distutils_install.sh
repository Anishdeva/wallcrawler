#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/cerlab/wallcrawler/src/roboclaw_ros/roboclaw_node"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/cerlab/wallcrawler/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/cerlab/wallcrawler/install/lib/python2.7/dist-packages:/home/cerlab/wallcrawler/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/cerlab/wallcrawler/build" \
    "/usr/bin/python2" \
    "/home/cerlab/wallcrawler/src/roboclaw_ros/roboclaw_node/setup.py" \
    build --build-base "/home/cerlab/wallcrawler/build/roboclaw_ros/roboclaw_node" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/cerlab/wallcrawler/install" --install-scripts="/home/cerlab/wallcrawler/install/bin"
