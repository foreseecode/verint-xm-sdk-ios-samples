cat <<static
## Installation
This project requires [CocoaPods](https://cocoapods.org/). After cloning, run:

    pod install

## Projects
All projects can be found in \`ForeSeeSamples.xcworkspace\`. Information about running each project follows.
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

