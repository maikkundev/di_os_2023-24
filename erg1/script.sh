# chmod +x script.sh

# Erwtima 1
cat /etc/passwd > passwd.out | cat /etc/group > group.out

# Erwtima 2
ls -la -lt > descending.out
ls -la -ltr  > ascending.out

# Erwtima 5

## Change the permissions of the house1 directory
chmod 640 $HOME/projects/house1

## Remove write permissions for the group from the projects dir and all its contents
chmod -R g-w $HOME/projects

# Erwtima 6

## Modify house1 file so that it contains 3 lines
echo -e "line1\nline2\nline3" > $HOME/projects/house1

## Modify house3 file so that it contains 3 lines with the first line matching the first line of house1
head -n 1 $HOME/projects/house1 | cat - $HOME/projects/house3 > $HOME/projects/house3_temp
mv $HOME/projects/house3_temp $HOME/projects/house3
rm -rf $HOME/projects/house3_temp

## Compare differences of house1 and house3
diff $HOME/projects/house1 $HOME/projects/house3