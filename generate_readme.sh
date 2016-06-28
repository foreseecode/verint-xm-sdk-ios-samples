cat <<static
# Sample Projects
static

for file in `ls *`
do
    if [ -d $file ]; then
        echo "##" `basename "$file"`
        if [ -e $file/README ]
        then
            cat "$file/README"
        fi;
        echo ""
    fi;
done;

