#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("GIRI");
MODULE_DESCRIPTION("A SIMPLE KERNEL MODULE");
MODULE_VERSION("1.0");

static int __init simplemodule_init(void)
{
	printk(KERN_INFO "KERNEL MODULE LOADED\n");
	return 0;
}

static void __exit simplemodule_exit(void)
{
	printk(KERN_INFO "KERNEL MODULE UNLOADED\n");
}

module_init(simplemodule_init);
module_exit(simplemodule_exit);

