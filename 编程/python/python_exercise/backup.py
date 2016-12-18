#!/bin/python3
''' This module is used to backup files

this is the fir version'''

import os
import time

#the files that need to be back
source = ['~/myBlog/*.md', '~/MyNote/*.txt']

#the backup folder
backup_dir='/var/backups/mybackup/'

#generate the backupfile name
target_filename = backup_dir + time.strftime('%Y%m%d%H%M%S')

#zip the files
#move the zip to backup folder
zip_command = "zip -vr '%s' %s" % (target_filename, ' '.join(source))

# Run
ret = os.system(zip_command)
if ret == 0:
    print('Successful backup to ', target)
else:
    print("Failed Backup", ret)


