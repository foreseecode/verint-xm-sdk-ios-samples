cat <<static
## Projects
All projects can be found in: \`ForeSeeSamples.xcworkspace\`
static

for file in */
do
    if [ -d $file ]; then
        if [ -e $file/README ]
        then
            echo "##" `basename "$file"`
            cat "$file/README"
        fi;
        echo ""
    fi;
done;

