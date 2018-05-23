#include <linux/module.h>    // included for all kernel modules
#include <linux/kernel.h>    // included for KERN_INFO
#include <linux/init.h>      // included for __init and __exit macros


static int __init hello_init(void)
{
    printk(KERN_INFO "Hello world!\n");  //KERN_DEBUG
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

static void  __exit hello_exit(void)
{
    printk(KERN_INFO "Good Bye Smita\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Smita");
MODULE_DESCRIPTION("A Simple Hello World module");

