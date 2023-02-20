# !/bin/bash
#ps -eo --format "cpu" --sort -%cpu | head -5

ps -e --format="uid uname cmd %cpu %mem time" --sort -%cpu | head -5

# ps aux --sort -%cpu
