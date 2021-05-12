#!/bin/bash
#---------------------------------------------------------------------
# AUTHOR: Dai (Paul) Vuong
# FILENAME: cal.bash
# SPECIFICATION: This program displays calendar of a specific month. 
# FOR: CS 2600- Homework #3
# TIME SPENT: 2 hours
#--------------------------------------------------------------------*/


daysInMonth()
{
  # This method return the number of days in a specific month
  # Params: month, year
  # Return: number of days

	monthInt=$1
	year=$2
    
	if [ "$monthInt" == 1 ] # Jan
    then
		return 31
	fi
	
	if [ "$monthInt" == 2 ] #Feb
    then        
		if [ $((year % 400)) -eq 0 ] # Check for Leap year
        then
            return 29
        elif [ $(($year % 4 )) -eq 0 -a $(($year % 400)) -ne 0 ]
        then
            return 29
        else
			return 28
		fi
	fi
	
	if [ "$monthInt" == 3 ] # Mar
    then
		return 31
	elif [ "$monthInt" == 4 ] # Apr
    then
		return 30
	elif [ "$monthInt" == 5 ] # May
    then
		return 31
	elif [ "$monthInt" == 6 ] # Jun
    then
		return 30
	elif [ "$monthInt" == 7 ] # Jul
    then 
		return 31
	elif [ "$monthInt" == 8 ] # Aug
    then
		return 31
	elif [ "$monthInt" == 9 ] # Sep
    then
		return 30
	elif [ "$monthInt" == 10 ] # Oct
    then
		return 31
	elif [ "$monthInt" == 11 ] #Nov
    then
		return 30
	elif [ "$monthInt" == 12 ] # Dec
    then
		return 31
	fi
}

firstDay()
{
  # This method return the first day of month
  # Params: year
  # Return: day
	year=$1
	temp=$((year - 1)) 
    ((res = ($year + $temp/4 - $temp/100 + $temp/400) % 7))
	return $res
}

header()
{
    # This method print the header
    # Params: month, year
    # Return: none
    mo=$1
    yr=$2

    monthsName=( "     January" "    February" "      March" "     April" "       May" 
                 "      June" "      July" "     August" "    September" "     October" "     November" "    December" )
    echo "${monthsName[$mo-1]}, $yr"
    echo " Su Mo Tu We Th Fr Sa"
}

printCal()
{
    # This method print out all days of the month
    # Params: month, year
    # Return: none
    year=$1
    month=$2

    firstDay $year # call the firstDay method
    current=$?

    for (( i = 1; i < 13; i++ )) # Go through 12 months
    do
        if [ $i -eq $month ]
        then
            header $i $year # print out the header
        fi

        daysInMonth $i $year # call the daysInMonth method
        days=$?

        for (( curr = 0; curr < current; curr++ ))
        do            
            if [ $i -eq $month ]
            then
                echo -n "   " # print blank space before the first day of the month
            fi
        done

        for (( j = 1; j <= days; j++ ))
        do
            if [ $i -eq $month ]
            then
                printf "%3d" "$j" # print days of the month
            fi           
            
            if (( ++curr > 6 ))
            then
                (( curr = 0 ))
                if [ $i -eq $month ] # go next line after a week
                then
                    echo
                fi
            fi
        done
        current=$curr
    done    
}

# Main

# Get the params from command line
month=$1
year=$2

# Covert string to number
re='^[0-9]+$'
if ! [[ $month =~ $re ]]
then
    m=0;
	for name in Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
	do
		if [ $name = $1 ]
		then
			break
		fi
		((m++))
	done
	month=$((m+1))
fi

# Catch error if user enter invalid month
if [ $month -gt 12 -o $month -lt 1 ]
then
    echo "Invalid month, must be between 1-12 OR 3 first character (Jan Feb Mar ...)"
    exit 0
fi

if [ $year -lt 1 -o $year -gt 9999 ]; then
    echo "Invalid year, must be greater than 0"
    exit 0
fi

# Add 2000 if user enter year less than 100
if [ $year -lt 100 ]; then
    (( year = year + 2000 ))
fi

printCal $year $month
