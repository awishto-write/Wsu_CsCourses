/*
 * procfs.c -  create a "file" in /proc
 */

#include <linux/kernel.h> /* We're doing kernel work */
#include <linux/module.h> /* Specifically, a module */
#include <linux/proc_fs.h> /* Necessary because we use the proc fs */
#include <linux/uaccess.h> /* For copy_from_user */
#include <linux/version.h>
#include <linux/string.h> /* For memset */

#define PROCFSREV_MAX_SIZE 1024
#define PROCFSREV_NAME "procbufrev"

/* This structure hold information about the /proc file */
static struct proc_dir_entry *our_proc_file;

/* The buffer used to store character for this module */
static char procfsrev_buffer[PROCFSREV_MAX_SIZE] = "HelloWorld!\n";

/* The size of the buffer */
static unsigned long procfsrev_buffer_size = 0;

/* This function is called then the /proc file is read */
static ssize_t procfile_read(struct file *file_pointer, char __user *buffer,
                             size_t buffer_length, loff_t *offset)
{   

   // procbufrev has an internal buffer 
    size_t _len = strlen(procfsrev_buffer) - *offset;
    size_t ret = _len;

      // When there is nothing else lfet and we are at the end
    if(_len <= 0) {
        return 0;
    }
 
      // Use the smallest value between them
    size_t _len_copy = min_t(size_t, buffer_length, _len);

         // Reverse the input found procfsrev_buffer
    char procfsrev_buffer_reversed[PROCFSREV_MAX_SIZE];
    for(size_t i = 0; i < _len_copy; i++){
        procfsrev_buffer_reversed = procfsrev_buffer[_len - i - 1];
        // Reverse from the current position 
    }

    if (copy_to_user(buffer, procfsrev_buffer, _len_copy)) {
        pr_info("copy_to_user failed\n");
        _ret = 0;
    }

    else {
        pr_info("procfile read /proc/%s\n", PROCFSREV_NAME);
        *offset += _len_copy;
    }
    
    return len_copy;
}

/* This function is called with the /proc file is written. */
static ssize_t procfile_write(struct file *file, const char __user *buff,
                              size_t len, loff_t *off)
{
	/* Clear internal buffer */
	memset(&procfsrev_buffer[0], 0, sizeof(procfs_buffer));
	
    procfsrev_buffer_size = len;
    if (procfsrev_buffer_size > PROCFSREV_MAX_SIZE)
        procfsrev_buffer_size = PROCFSREV_MAX_SIZE;

    if (copy_from_user(procfsrev_buffer, buff, procfsrev_buffer_size))
        return -EFAULT;

    procfs_buffer[procfsrev_buffer_size & (PROCFSREV_MAX_SIZE - 1)] = '\0';
    *off += procfsrev_buffer_size;
    pr_info("procfile write %s\n", procfsrev_buffer);

    return procfsrev_buffer_size;
}

static const struct proc_ops proc_file_fops = {
    .proc_read = procfile_read,
    .proc_write = procfile_write,
};


static int __init procfsrev2_init(void)
{
    our_proc_file = proc_create(PROCFSREV_NAME, 0644, NULL, &proc_file_fops);
    if (NULL == our_proc_file) {
        pr_alert("Error:Could not initialize /proc/%s\n", PROCFSREV_NAME);
        return -ENOMEM;
    }

    pr_info("/proc/%s created\n", PROCFSREV_NAME);
    return 0;
}

static void __exit procfsrev2_exit(void)
{
    proc_remove(our_proc_file);
    pr_info("/proc/%s removed\n", PROCFSREV_NAME);
}

module_init(procfsrev2_init);
module_exit(procfsrev2_exit);

MODULE_LICENSE("GPL");
