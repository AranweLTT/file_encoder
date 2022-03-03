mkdir -p locked;
for i in ./unlocked/*.*; 
do 
	echo $i;
    	sha256sum "$i" >> checksum.txt;
    	./file_encoder "$i" "locked/$(basename "$i")" 117 101 62 176 83 82 103 213 189;
done
