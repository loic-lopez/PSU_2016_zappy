#!/usr/bin/env bash

if [ $# -lt 4 ]
then
    	echo "./launchAiClients.sh [NBR_AI] [TEAM_NAME] [SERVER_ADDR] [SERVER_PORT]"
        exit
fi

declare -i nbAiClient=$((10#$1))
team=$2
host=$3
declare	-i port=$4

if [ ${nbAiClient} -eq 0 ]
then
        echo "Number of ai clients must be greater than 0"
else
	currentNbrAi=0
	firstPid=0
	start=0
	while [ ${currentNbrAi} -lt ${nbAiClient} ]
	do
		if [ ${start} -eq 0 ]
		then
			./zappy_ai -p ${port} -n ${team} -h ${host} &
			start=$(( $start + 1 ))
			until firstPid=$(pidof zappy_ai)
			do
				sleep 1
			done
		else
			./zappy_ai -p ${port} -n ${team} -h ${host} &
			pid=$(pidof zappy_ai)
			until pid=${pid[${#pid[@]} - 1]}
			do
				sleep 1
			done

		fi
		currentNbrAi=$(( $currentNbrAi + 1 ))
	done
	while ps -p ${firstPid} > /dev/null; do sleep 1; done;
fi
