cat <<static
## Projects
All projects can be found in: \`ForeSeeSamples.xcworkspace\`
static

for file in */
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

