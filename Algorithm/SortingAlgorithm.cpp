//
//Sorting Algorithm
#include "SortingAlgorithm.hpp"
//Accomplished [X] as measured by [Y] by doing [Z]!!!!!!!

/*
首先，排序算法的稳定性大家应该都知道，通俗地讲就是能保证排序前2个相等的数其在序列的前后位置顺序和排序后它们两个的前后位置顺序相同。
在简单形式化一下，如果Ai = Aj，Ai原来在位置前，排序后Ai还是要在Aj位置前。

其次，说一下稳定性的好处。排序算法如果是稳定的，那么从一个键上排序，然后再从另一个键上排序，第一个键排序的结果可以为第二个键排序所用。
基数排序就是这样，先按低位排序，逐次按高位排序，低位相同的元素其顺序再高位也相同时是不会改变的。
另外，如果排序算法稳定，对基于比较的排序算法而言，元素交换的次数可能会少一些（个人感觉，没有证实）。

选择排序、快速排序、希尔排序、堆排序不是稳定的排序算法，而冒泡排序、插入排序、归并排序和基数排序是稳定的排序算法
*/
namespace sort {
	int SortingAlgorithm(int argc, char* argv) //Put it in main
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		do
		{
			int *arr;
			unsigned int n, tag;
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			puts("\\\***Sorting Algorithm***///");//八大排序  =>12排序
			puts("Please enter the length of the array(Press 0 exit)");//请输入要排序的数组的长度(输入0退出)
			scanf_s("%d", &n);
			if (n) arr = (int *)malloc(n * sizeof(int));
			else return 0;
			do
			{
				puts("Please enter all the elements in the array(elements exceed the length will not be recorded):\n");//请输入要排序数组的全部元素(超过长度的元素将不被录入)
				for (int i = 0; i < n; i++)
					scanf_s("%d", arr + i);
				while (getchar() != '\n');
				puts("Input array:");//输入的数组(按回车确认，按C重新输入)
				for (int i = 0; i < n; i++)
					printf("%d\t", *(arr + i));
				puts("");
				if (getchar() != 'C') break;
			} while (1);
			puts("Please Enter the sorting method tag:");//请选择排序类型
			puts("Simple Sorts:\n[1]:Insertion Sort*\t[2]:Selection Sort*\t[3]:Binary Search");
			puts("Efficient Sorts:\n[4]:Merge Sort*\t\t[5]:Heap Sort*\t\t[6]:Quick Sort*");
			puts("Bubble Sort and Variants:\n[7]:Bubble Sort*\t[8]:Sell Sort*\t\t[9]:Comb Sort");
			puts("Distribution Sorts:\n[10]:Counting Sort\t[11]:Bucket Sort\t[12]:Radix Sort*");
			scanf_s("%d", &tag);
			getchar();
			system("cls");
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			/*
			Each function mainly recieves two inputs: target array and the its length
			The
			*/
			switch (tag)
			{
			case 1: puts("[1]:Insertion Sort"); insertion_sort(arr, n); break;
			case 2: puts("[2]:Selection Sort"); selection_sort(arr, n); break;
			case 3: puts("[3]:Binary Sort"); binary_sort(arr, n); break;
			case 4: puts("[4]:Merge Sort"); merge_sort(arr, 0, (n - 1)); break;
			case 5: puts("[5]:Heap Sort"); heap_sort(arr, n); break;
			case 6: puts("[6]Quick Sort"); quick_sort(arr, 0, n - 1); break;
			case 7: puts("[7]:Bubble Sort"); bubble_sort(arr, n); break;
			case 8: puts("[8]:Shell Sort"); shell_sort(arr, 0, n - 1); break;
			case 9: puts("[9]:Comb Sort"); comb_sort(arr, n); break;
			case 10: puts("[10]:Counting Sort"); counting_sort(arr, n); break;
			case 11: puts("[11]:Bucket Sort"); bucket_sort(arr, n); break;
			case 12: puts("[12]:Radix Sort"); radix_sort(arr, n); break;
			default:
				puts("Invalid Input");
				break;
			}
			puts("Sorted array:\n");//排序后的数组
			for (int a = 0; a < n; a++)
				printf("%d\t", *(arr + a));
			putchar('\n');
			getchar();
			system("cls");
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
			puts("\nDO IT AGAIN?\nPress any key to return the menu,or Press 0 to leave");
			if (getchar() == '0')
				break;
			system("cls");
		} while (1);
		return EXIT_SUCCESS;
	}


	//Generate random array for testing performance when dealing with large quantities of array
	int *generateRandArr(int size, int interval)
	{
		int *dist = (int *)malloc(sizeof(int)*size);
		for (int i = 0; i < size; i++)
			dist[i] = rand() % interval;
		return dist;
	}


	/*Simple Sorts*/
	//insertion_sort
	//插入排序
	/*
	插入排序是一种最简单直观的排序算法，它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
	算法步骤：
	1）将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
	2）从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
	*/
	int insertion_sort(int *arr, unsigned int n)
	{
		for (int i = 1; i < n; i++)
		{
			int j, temp = *(arr + i);
			for (j = i; (j > 0) && (*(arr + (j - 1)) > temp); j--)
				*(arr + j) = *(arr + (j - 1));
			*(arr + j) = temp;
		}
		return EXIT_SUCCESS;
	}
	//selection_sort
	//选择排序
	/*
	算法步骤：
	1）首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置
	2）再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
	3）重复第二步，直到所有元素均排序完毕。
	*/
	int selection_sort(int *arr, unsigned int n)
	{
		int i, j, min, t;
		for (i = 0; i < n - 1; i++)
		{
			min = i;
			for (j = i + 1; j < n; j++)
				if (arr[min] > arr[j])
					min = j;
			if (min != i)
			{
				t = arr[min];
				arr[min] = arr[i];
				arr[i] = t;
			}
		}
		return EXIT_SUCCESS;
	}
	//binary_sort
	//二分排序
	/*
	没啥好说的
	时间复杂度（logn)
	*/
	int binary_sort(int *arr, int n)
	{
		int low, high, mid;
		int temp;
		for (int i = 1; i < n; i++)
		{
			temp = arr[i];
			low = 0;
			high = i - 1;
			while (low <= high)
			{
				mid = (low + high) / 2;
				if (arr[mid] > temp)
					high = mid - 1;
				else
					low = mid + 1;
			}
			for (int j = i - 1; j > high; j--)
				arr[j + 1] = arr[j];
			arr[high + 1] = temp;
		}
		return EXIT_SUCCESS;
	}

	/*Efficient Sorts*/
	//merge_sort
	/*
	归并排序（Merge sort）是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。
	归并排序是把序列递归地分成短序列，递归出口是短序列只有1个元素（认为直接有序）或者2个序列（1次比较和交换），然后把各个有序的段序列合并成一个有序的长序列，不断合并直到原序列全部排好序。
	可以发现，在1个或2个元素时，1个元素不会交换，2个元素如果大小相等也没有人故意交换，这不会破坏稳定性。
	那么，在短的有序序列合并的过程中，稳定是是否受到破坏？没有，合并过程中我们可以保证如果两个当前元素相等时，我们把处在前面的序列的元素保存在结果序列的前面，这样就保证了稳定性。
	所以，归并排序也是稳定的排序算法。
	算法步骤：
	1) 申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列
	2) 设定两个指针，最初位置分别为两个已经排序序列的起始位置
	3) 比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置
	4) 重复步骤3直到某一指针达到序列尾
	5) 将另一序列剩下的所有元素直接复制到合并序列尾
	*/
	int Merge(int *sourceArr, int startIndex, int midIndex, int endIndex)
	{
		int i = startIndex, j = midIndex + 1, k = startIndex;
		int  *tempArr = (int *)malloc(sizeof(int)*(endIndex - startIndex +1));
		while (i != midIndex + 1 && j != endIndex + 1)
		{
			if (sourceArr[i] >= sourceArr[j])
				tempArr[k++] = sourceArr[j++];
			else
				tempArr[k++] = sourceArr[i++];
		}
		while (i != midIndex + 1)
			tempArr[k++] = sourceArr[i++];
		while (j != endIndex + 1)
			tempArr[k++] = sourceArr[j++];
		for (i = startIndex; i <= endIndex; i++)
			sourceArr[i] = tempArr[i];
		return EXIT_SUCCESS;
	}
	//内部使用递归
	int merge_sort(int *arr, int startIndex, int endIndex)
	{
		if (startIndex < endIndex)
		{
			int midIndex = (startIndex + endIndex) / 2;
			merge_sort(arr, startIndex, midIndex);
			merge_sort(arr, midIndex + 1, endIndex);
			Merge(arr, startIndex, midIndex, endIndex);
		}
		//putchar('\n');
		return EXIT_SUCCESS;
	}
	//heap_sort
	//堆排序
	/*
	堆排序（Heapsort）是指利用堆这种数据结构所设计的一种排序算法。堆积是一个近似完全二叉树的结构，并同时满足堆积的性质：即子结点的键值或索引总是小于（或者大于）它的父节点。
	堆排序的平均时间复杂度为Ο(nlogn) 。
	算法步骤：
	1）创建一个堆H[0..n-1]
	2）把堆首（最大值）和堆尾互换
	3）把堆的尺寸缩小1，并调用shift_down(0),目的是把新的数组顶端数据调整到相应位置
	4） 重复步骤2，直到堆的尺寸为1
	*/
	//array是待调整的堆数组，i是待调整的数组元素的位置，nlength是数组的长度
	//本函数功能是：根据数组array构建大根堆
	int HeapAdjust(int *arr, int i, int nLength)
	{
		int nChild;
		int nTemp;
		for (; 2 * i + 1 < nLength; i = nChild)
		{
			//子结点的位置=2*（父结点位置）+1
			nChild = 2 * i + 1;
			//得到子结点中较大的结点
			if (nChild < nLength - 1 && arr[nChild + 1] > arr[nChild]) ++nChild;
			//如果较大的子结点大于父结点那么把较大的子结点往上移动，替换它的父结点
			if (arr[i] < arr[nChild])
			{
				nTemp = arr[i];
				arr[i] = arr[nChild];
				arr[nChild] = nTemp;
			}
			else break; //否则退出循环
		}
		return EXIT_SUCCESS;
	}
	//堆排序算法
	int heap_sort(int *arr, int n)
	{
		int i;
		//调整序列的前半部分元素，调整完之后第一个元素是序列的最大的元素
		//length/2-1是最后一个非叶节点，此处"/"为整除
		for (i = n / 2 - 1; i >= 0; --i)
			HeapAdjust(arr, i, n);
		//从最后一个元素开始对序列进行调整，不断的缩小调整的范围直到第一个元素
		for (i = n - 1; i > 0; --i)
		{
			//把第一个元素和当前的最后一个元素交换，
			//保证当前的最后一个位置的元素都是在现在的这个序列之中最大的
			arr[i] = arr[0] ^ arr[i];
			arr[0] = arr[0] ^ arr[i];
			arr[i] = arr[0] ^ arr[i];
			//不断缩小调整heap的范围，每一次调整完毕保证第一个元素是当前序列的最大值
			HeapAdjust(arr, 0, i);
		}
		return EXIT_SUCCESS;
	}
	//quick_sort
	//快速排序
	/*
	快速排序有两个方向，左边的i下标一直往右走，当a[i] <= a[center_index]，其中center_index是中枢元素的数组下标，一般取为数组第0个元素。
	而右边的j下标一直往左走，当a[j] > a[center_index]。
	如果i和j都走不动了，i <= j，交换a[i]和a[j],重复上面的过程，直到i > j。
	交换a[j]和a[center_index]，完成一趟快速排序。
	在中枢元素和a[j]交换的时候，很有可能把前面的元素的稳定性打乱，比如序列为5 3 3 4 3 8 9 10 11，现在中枢元素5和3（第5个元素，下标从1开始计）交换就会把元素3的稳定性打乱，所以快速排序是一个不稳定的排序算法，不稳定发生在中枢元素和a[j] 交换的时刻。
	*/
	int quick_sort(int *arr, int left, int right)
	{
		if (left < right)//表示已经完成一个组
		{
			int i = left, j = right, x = arr[left];
			while (i < j)
			{
				while ((i < j) && (arr[j] >= x)) j--;
				if (i < j) arr[i++] = arr[j];
				while ((i < j) && (arr[j] < x)) i++;
				if (i < j) arr[j--] = arr[i];
			}
			arr[i] = x;
			quick_sort(arr, left, i - 1);
			quick_sort(arr, i + 1, right);
		}
		return EXIT_SUCCESS;
	}

	//bubble_sort
	//冒泡排序
	int bubble_sort(int *arr, int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			BOOL flag = 1;
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
					flag = 0;
				}
			}
			if (flag) break;
		}
		return EXIT_SUCCESS;
	}
	//shell_sort
	//希尔排序
	int shell_sort(int *arr, int start, int end)
	{
		int increment = end - start + 1;    //初始化划分增量
		do {    //每次减小增量，直到increment = 1
			increment = increment / 3 + 1;
			for (int i = start + increment; i <= end; ++i) {    //对每个划分进行直接插入排序
				if (arr[i - increment] > arr[i]) {
					int temp = arr[i];
					int j = i - increment;
					do {    //移动元素并寻找位置
						arr[j + increment] = arr[j];
						j -= increment;
					} while (j >= start && arr[j] > temp);
					arr[j + increment] = temp;  //插入元素
				}
			}
		} while (increment > 1);
		return EXIT_SUCCESS;
	}
	//comb_sort
	//梳排序
	/*
	基本思想：梳排序和希尔排序很类似。希尔排序是在直接插入排序的基础上做的优化，而梳排序是在冒泡排序的基础上做的优化。
	也是想希尔排序一样，将待排序序列通过增量分为若干个子序列，然后对子序列进行一趟冒泡排序，一步步减小增量，直至增量为1。所以梳排序的最后一次排序是冒泡排序。
	梳排序增量是根据递减率减小的，递减率的设定影响着梳排序的效率。
	*/
#define     LAPSE_RATE  1.3 //以随机数作实验，得到最有效递减率为1.3，有待验证
	BOOL comb_sort(int *arr, int size)
	{
		int i, j;
		int increment;
		if (arr == NULL)
			return FALSE;
		increment = size;
		while (TRUE) {
			increment = (int)(increment / LAPSE_RATE);
			for (i = 0; i < increment; i++) {
				for (j = i + increment; j < size; j += increment)
				{
					if (arr[j] < arr[j - increment])
					{
						int temp = arr[j];
						arr[j] = arr[j - increment];
						arr[j - increment] = temp;
					}
				}
			}
			if (increment <= 1)
				break;
		}
		return EXIT_SUCCESS;
	}

	//counting_sort
	//计数排序
	/*
	计数排序是一个非基于比较的排序算法，该算法于1954年由 Harold H. Seward 提出。
	它的优势在于在对一定范围内的整数排序时，它的复杂度为Ο(n+k)（其中k是整数的范围），快于任何比较排序算法。
	当然这是一种牺牲空间换取时间的做法，而且当O(k)>O(n*log(n))的时候其效率反而不如基于比较的排序（基于比较的排序的时间复杂度在理论上的下限是O(n*log(n)), 如归并排序，堆排序）
	*/
	int counting_sort(int *arr, int n)
	{
		int *ballot; //counter to store the numbers of each element
		int max = arr[0], min = arr[0];
		for (int i = 1; i < n; i++)
		{
			max = max > arr[i] ? max : arr[i];
			min = min < arr[i] ? min : arr[i];
		}
		ballot = (int *)malloc(sizeof(int)*(max - min));
		memset(ballot, 0, n);
		for (int i = 0; i < n; i++)
			ballot[arr[i]]++;

		/* Awesome Way to do that yet require additional array to store the sorted result */
		for (int i = 0; i < (max - min); i++) //adjust index to the last position
			ballot[i] += ballot[i - 1];
		int *dist = (int *)malloc(sizeof(int)*n);
		for (int i = n; i > 0; i--)
		{
			dist[ballot[arr[i - 1]] - 1] = arr[i - 1];
			ballot[arr[i - 1]]--;
		}
		free(ballot);
		for (int i = 0; i < n; i++)
			printf("%d\t", dist[i]);
		/**/
		/*
		int value = max;
		for (int i = n - 1; i > -1;i--)
		{
			if (value < min)
				break;
			if (ballot[i]) {
				printf("%d", ballot[i]);
				arr[i] = value;
				ballot[i]--;
				}

			value--;
		}
		*/
		return EXIT_SUCCESS;
	}
	//bucket_sort
	//箱排序
	/*
	桶排序 (Bucket sort)或所谓的箱排序，是一个排序算法，工作的原理是将数组分到有限数量的桶子里。
	每个桶子再个别排序（有可能再使用别的排序算法或是以递归方式继续使用桶排序进行排序）。桶排序是鸽巢排序的一种归纳结果。
	当要被排序的数组内的数值是均匀分配的时候，桶排序使用线性时间（Θ（n））。但桶排序并不是 比较排序，他不受到 O(n log n) 下限的影响。

	*/
	int bucket_sort(int *arr, int n)
	{

		return EXIT_SUCCESS;
	}
	//radix_sort
	//基数排序
	/*基数排序（radix sort）属于“分配式排序”（distribution sort），又称“桶子法”（bucket sort）或bin sort，
	顾名思义，它是透过键值的部份资讯，将要排序的元素分配至某些“桶”中，藉以达到排序的作用，基数排序法是属于稳定性的排序，
	其时间复杂度为O (nlog(r)m)，其中r为所采取的基数，而m为堆数，在某些时候，基数排序法的效率高于其它的稳定性排序法。
	基数排序又称为“桶子法”，从低位开始将待排序的数按照这一位的值放到相应的编号为0~9的桶中。
	等到低位排完得到一个子序列，再将这个序列按照次低位的大小进入相应的桶中，一直排到最高位为止，数组排序完成。
	方法：
	MSD: 最高位优先(Most Significant Digit first)法，简称MSD法：先按k1排序分组，同一组中记录，关键码k1相等，再对各组按k2排序分成子组，之后，对后面的关键码继续这样的排序分组，直到按最次位关键码kd对各子组排序后。再将各组连接起来，便得到一个有序序列。
	LSD: 最低位优先(Least Significant Digit first)法，简称LSD法：先从kd开始排序，再对kd-1进行排序，依次重复，直到对k1排序后便得到一个有序序列。
	时间复杂度：O(N*digit)
	空间复杂度：O(N)
	稳定性：稳定
	*/
	int radix_sort(int *arr, int n)
	{

		return EXIT_SUCCESS;
	}
}