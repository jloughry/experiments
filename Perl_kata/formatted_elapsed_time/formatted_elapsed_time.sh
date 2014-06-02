#!/bin/sh

elapsed_time="12345"

formatted_elapsed_time=`echo $elapsed_time | perl -e 'my $sec = <>; printf "%dd %dh %dm %ds", \
    int($sec/(24*60*60)), ($sec/(60*60))%24, ($sec/60)%60, $sec%60;'`

echo "elapsed_time $elapsed_time seconds ($formatted_elapsed_time)"

