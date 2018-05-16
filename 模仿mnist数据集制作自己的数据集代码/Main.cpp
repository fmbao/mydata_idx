#include "Image_to_BinaryData.h"

int main()
{
	Image2BinaryData IBD(28,28);											//����ͼƬ��С(Height,Width)
	
	/*------------����ѵ�����ļ�--------------------------*/
	printf("----------����ѵ�����ļ�-------------\n");
	string trainfilefolder = "C:\\Users\\lyf\\Desktop\\mnist\\train_images";		//ѵ��ͼƬ�ļ�·��
	vector<string> trainfileLists = IBD.getFileLists(trainfilefolder);				//����ļ����б�

	const int train_size_list = trainfileLists.size();
	cout << "Images Number: " << train_size_list << endl;							//����ļ�����

	string trainimagebinfilepath = "C:\\Users\\lyf\\Desktop\\train-images-idx3-ubyte";		//ѵ��ͼƬת������·��
	string trainlabelbinfilepath = "C:\\Users\\lyf\\Desktop\\train-labels-idx1-ubyte";		//ѵ����ǩת������·��
	vector<cv::Mat> TrainImagesMat;															//�����洢ѵ��ͼƬ����ֵ
	vector<int> train_image_labels(train_size_list);										//�����洢ѵ�����ǩ�б�
	IBD.ReadImage(trainfilefolder, trainfileLists, train_image_labels, TrainImagesMat);		//��ȡѵ��ͼƬ
	IBD.Image2BinaryFile(trainimagebinfilepath, TrainImagesMat, train_image_labels);		//ѵ��ͼƬת�������ļ�
	IBD.Label2BinaryFile(trainlabelbinfilepath, train_image_labels);						//ѵ����ǩת�������ļ�

	/*------------���ɲ��Լ��ļ�--------------------------*/
	printf("\n\n----------���ɲ��Լ��ļ�-------------\n");
	string testfilefolder = "C:\\Users\\lyf\\Desktop\\mnist\\test_images";		//����ͼƬ�ļ�·��
	vector<string> testfileLists = IBD.getFileLists(testfilefolder);			//����ļ����б�
	
	const int test_size_list = testfileLists.size();
	cout << "Images Number: " << test_size_list << endl;									//����ļ�����
	string testimagebinfilepath = "C:\\Users\\lyf\\Desktop\\t10k-images-idx3-ubyte";		//����ͼƬת������·��
	string testlabelbinfilepath  = "C:\\Users\\lyf\\Desktop\\t10k-labels-idx1-ubyte";		//���Ա�ǩת������·��
	vector<cv::Mat> TestImagesMat;															//�����洢����ͼƬ����ֵ
	vector<int> test_image_labels(test_size_list);											//�����洢�������ǩ�б�
	IBD.ReadImage(testfilefolder, testfileLists, test_image_labels, TestImagesMat);			//��ȡ����ͼƬ
	IBD.Image2BinaryFile(testimagebinfilepath, TestImagesMat, test_image_labels);			//����ͼƬת�������ļ�
	IBD.Label2BinaryFile(testlabelbinfilepath, test_image_labels);							//���Ա�ǩת�������ļ�

	return 0;
}