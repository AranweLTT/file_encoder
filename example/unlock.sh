mkdir -p unlocked;
for i in ./locked/*.*; 
do 
	echo $i;
    	./file_encoder "$i" "unlocked/$(basename "$i")" 109 101 64 78 143 102 171 10 159;
done
