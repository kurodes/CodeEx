        #iostat for io and cpu usage
        iostat -cdxz 1 | tee tmp_iostat &
        PID_iostat=$!
        echo $PID_iostat
sleep 10
        kill $PID_iostat

