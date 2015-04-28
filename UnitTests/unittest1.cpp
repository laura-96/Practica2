#include "stdafx.h"
#include "CppUnitTest.h"


#include "../Tree.h"
#include "../Linked_List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(PreOrderRecursive)
		{


			Tree<char> arbre('F');
			p2List<TreeNode<char>*> list;


			arbre.Add('B', 'F');
			arbre.Add('G', 'F');
			arbre.Add('A', 'B');
			arbre.Add('D', 'B');
			arbre.Add('X', 'B');
			arbre.Add('C', 'D');
			arbre.Add('E', 'D');
			arbre.Add('I', 'G');
			arbre.Add('H', 'I');

			arbre.PreOrderRecursive(&list);

			Assert::IsTrue((char)list.Index(0)->data == 'F');
			Assert::IsTrue((char)list.Index(1)->data == 'B');
			Assert::IsTrue((char)list.Index(2)->data == 'G');
			Assert::IsTrue((char)list.Index(3)->data == 'A');
			Assert::IsTrue((char)list.Index(4)->data == 'D');
			Assert::IsTrue((char)list.Index(5)->data == 'X');
			Assert::IsTrue((char)list.Index(6)->data == 'C');
			Assert::IsTrue((char)list.Index(7)->data == 'E');
			Assert::IsTrue((char)list.Index(8)->data == 'I');
			Assert::IsTrue((char)list.Index(9)->data == 'H');
		}

		TEST_METHOD(InOrderRecursive)
		{


			Tree<char> arbre('F');
			p2List<TreeNode<char>*> list;


			arbre.Add('B', 'F');
			arbre.Add('G', 'F');
			arbre.Add('A', 'B');
			arbre.Add('D', 'B');
			arbre.Add('X', 'B');
			arbre.Add('C', 'D');
			arbre.Add('E', 'D');
			arbre.Add('I', 'G');
			arbre.Add('H', 'I');

			arbre.InOrderRecursive(&list);

			Assert::IsTrue((char)list.Index(0)->data == 'A');
			Assert::IsTrue((char)list.Index(1)->data == 'B');
			Assert::IsTrue((char)list.Index(2)->data == 'C');
			Assert::IsTrue((char)list.Index(3)->data == 'D');
			Assert::IsTrue((char)list.Index(4)->data == 'E');
			Assert::IsTrue((char)list.Index(5)->data == 'X');
			Assert::IsTrue((char)list.Index(6)->data == 'F');
			Assert::IsTrue((char)list.Index(7)->data == 'G');
			Assert::IsTrue((char)list.Index(8)->data == 'I');
			Assert::IsTrue((char)list.Index(9)->data == 'H');
		}


		TEST_METHOD(PostOrderRecursive)
		{


			Tree<char> arbre('F');
			p2List<TreeNode<char>*> list;


			arbre.Add('B', 'F');
			arbre.Add('G', 'F');
			arbre.Add('A', 'B');
			arbre.Add('D', 'B');
			arbre.Add('X', 'B');
			arbre.Add('C', 'D');
			arbre.Add('E', 'D');
			arbre.Add('I', 'G');
			arbre.Add('H', 'I');

			arbre.PostOrderRecursive(&list);

			Assert::IsTrue((char)list.Index(0)->data == 'A');
			Assert::IsTrue((char)list.Index(1)->data == 'C');
			Assert::IsTrue((char)list.Index(2)->data == 'E');
			Assert::IsTrue((char)list.Index(3)->data == 'D');
			Assert::IsTrue((char)list.Index(4)->data == 'X');
			Assert::IsTrue((char)list.Index(5)->data == 'B');
			Assert::IsTrue((char)list.Index(6)->data == 'H');
			Assert::IsTrue((char)list.Index(7)->data == 'I');
			Assert::IsTrue((char)list.Index(8)->data == 'G');
			Assert::IsTrue((char)list.Index(9)->data == 'F');
		}

		TEST_METHOD(PreOrderIterative)
		{


			Tree<char> arbre('F');
			p2List<TreeNode<char>*> list;


			arbre.Add('B', 'F');
			arbre.Add('G', 'F');
			arbre.Add('A', 'B');
			arbre.Add('D', 'B');
			arbre.Add('X', 'B');
			arbre.Add('C', 'D');
			arbre.Add('E', 'D');
			arbre.Add('I', 'G');
			arbre.Add('H', 'I');

			arbre.PreOrderIterative(&list);

			Assert::IsTrue((char)list.Index(0)->data == 'F');
			Assert::IsTrue((char)list.Index(1)->data == 'B');
			Assert::IsTrue((char)list.Index(2)->data == 'G');
			Assert::IsTrue((char)list.Index(3)->data == 'A');
			Assert::IsTrue((char)list.Index(4)->data == 'D');
			Assert::IsTrue((char)list.Index(5)->data == 'X');
			Assert::IsTrue((char)list.Index(6)->data == 'C');
			Assert::IsTrue((char)list.Index(7)->data == 'E');
			Assert::IsTrue((char)list.Index(8)->data == 'I');
			Assert::IsTrue((char)list.Index(9)->data == 'H');
		}

		TEST_METHOD(PostOrderIterative)
		{


			Tree<char> arbre('F');
			p2List<TreeNode<char>*> list;


			arbre.Add('B', 'F');
			arbre.Add('G', 'F');
			arbre.Add('A', 'B');
			arbre.Add('D', 'B');
			arbre.Add('X', 'B');
			arbre.Add('C', 'D');
			arbre.Add('E', 'D');
			arbre.Add('I', 'G');
			arbre.Add('H', 'I');

			arbre.PostOrderIterative(&list);

			Assert::IsTrue((char)list.Index(0)->data == 'A');
			Assert::IsTrue((char)list.Index(1)->data == 'C');
			Assert::IsTrue((char)list.Index(2)->data == 'E');
			Assert::IsTrue((char)list.Index(3)->data == 'D');
			Assert::IsTrue((char)list.Index(4)->data == 'X');
			Assert::IsTrue((char)list.Index(5)->data == 'B');
			Assert::IsTrue((char)list.Index(6)->data == 'H');
			Assert::IsTrue((char)list.Index(7)->data == 'I');
			Assert::IsTrue((char)list.Index(8)->data == 'G');
			Assert::IsTrue((char)list.Index(9)->data == 'F');
		}

		TEST_METHOD(Clear)
		{
			Tree<char> arbre('F');
			p2List<TreeNode<char>*> list;

			arbre.Add('B', 'F');
			arbre.Add('G', 'F');
			arbre.Add('A', 'B');
			arbre.Add('D', 'B');
			arbre.Add('X', 'B');
			arbre.Add('C', 'D');
			arbre.Add('E', 'D');
			arbre.Add('I', 'G');
			arbre.Add('H', 'I');

			arbre.Clear();



			Assert::IsTrue(list.getFirst(), NULL);
		}

	};
}