#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("smita");

static int hello_init(void)
{
	pr_debug("Hello World!\n");
	return 0;

}

static void hello_exit(void)
{
	return;
}

module_init(hello_init);
module_exit(hello_exit);


