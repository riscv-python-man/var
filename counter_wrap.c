#include <linux/init.h>
#include <linux/module.h>
#include <linux/jiffies.h>

static int __init hello_mode_init(void)
{
	unsigned long j1=0x7ffffffffffffff0;
	unsigned long time_base=0x7fffffffffffffff;
	unsigned long j2=0x8000000000000002;

	printk("j2:%ld, time_base:%ld\n", (long)j2, (long)time_base);
	printk("typecheck(unsigned long, j2):%d,typecheck(unsigned long, time_base):%d\n", 
			typecheck(unsigned long,j2), typecheck(unsigned long, time_base));

	printk("singned AND unsigned boundary ..\n");
	printk("0x%lx - 0x%lx:%ld \n", time_base, j1, (long)time_base - (long)j1);
	printk("0x%lx - 0x%lx:%ld \n", j2, time_base, (long)j2 - (long)time_base);
	printk("0x%lx - 0x%lx:%ld \n", j2, j1, (long)j2 - (long)j1);

	time_base=0xfffffffffffffff0;
	j2=0x2;

	printk("zero point boundary ..\n");
	printk("0x%lx - 0x%lx:%ld \n", j2, time_base, (long)j2 - (long)time_base);


	return 0;
}

static void __exit hello_mode_exit(void)
{
	printk(KERN_EMERG "module_exit!\n");
}

module_init(hello_mode_init);
module_exit(hello_mode_exit);

MODULE_LICENSE("Dual BSD/GPL");
