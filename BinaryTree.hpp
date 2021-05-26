#pragma once
namespace ariel{
    template<typename T>
    class BinaryTree {
    private:
        T *root;
    public:
        void add_root(const & T val) {

        }

        void add_left(const & T val) {

        }
        
        void add_right(const & T val) {

        }


    private:

        // // Avoid copying
        // Stk (const Stk& rhs);
        // Stk& operator=(const Stk& rhs);

        // inner class
        struct Node {
            T m_value;
            Node *m_next;

            Node(const T &v, Node *n)
                    : m_value(v), m_next(n) {
            }
        };

        // fields
        Node *m_first;

    public:

        //-------------------------------------------------------------------
        // iterator related code:
        // inner class and methods that return instances of it)
        //-------------------------------------------------------------------
        class iterator {

        protected:
            Node *pointer_to_current_node;

        public:

            iterator(Node *ptr = nullptr)
                    : pointer_to_current_node(ptr) {
            }

            // Note that the method is const as this operator does not
            // allow changing of the iterator.
            // Note that it returns T& as it allows to change what it points to.
            // A const_iterator class will return const T&
            // and the method will still be const
            T &operator*() const {
                //return *pointer_to_current_node;
                return pointer_to_current_node->m_value;
            }

            T *operator->() const {
                return &(pointer_to_current_node->m_value);
            }

            // // ++i;
            // virtual iterator& operator++()=0;
            // // {
            // // 	//++pointer_to_current_node;
            // // 	pointer_to_current_node = pointer_to_current_node->m_next;
            // // 	return *this;
            // // }

            // // i++;
            // // Usually iterators are passed by value and not by const& as they are small.
            // virtual const iterator operator++(int)=0;
            // // {
            // // 	iterator tmp= *this;
            // // 	pointer_to_current_node= pointer_to_current_node->m_next;
            // // 	return tmp;
            // // }

            bool operator==(const iterator &rhs) const {
                return pointer_to_current_node == rhs.pointer_to_current_node;
            }

            bool operator!=(const iterator &rhs) const {
                return pointer_to_current_node != rhs.pointer_to_current_node;
            }
        };  // END OF CLASS ITERATOR
        class iterator_preorder : public iterator {


        public:

            iterator_preorder(Node *ptr = nullptr) : iterator(ptr) {}

            // ++i;
            virtual iterator_preorder &operator++() {
                //++pointer_to_current_node;
                this->pointer_to_current_node = this->pointer_to_current_node->m_next;
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            virtual const iterator_preorder operator++(int) {
                iterator tmp = *this;
                this->pointer_to_current_node = this->pointer_to_current_node->m_next;
                return tmp;
            }


        };  // END OF CLASS ITERATOR_PREORDER
        class iterator_inorder : public iterator {

        public:

            iterator_inorder(Node *ptr = nullptr) : iterator(ptr) {}


            // ++i;
            virtual iterator_inorder &operator++() {
                //++pointer_to_current_node;
                this->pointer_to_current_node = this->pointer_to_current_node->m_next;
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            virtual const iterator_inorder operator++(int) {
                iterator tmp = *this;
                this->pointer_to_current_node = this->pointer_to_current_node->m_next;
                return tmp;
            }


        };  // END OF CLASS ITERATOR_INORDER
        class iterator_postorder : public iterator {
        public:

            iterator_postorder(Node *ptr = nullptr) : iterator(ptr) {}


            // ++i;
            virtual iterator_postorder &operator++() {
                //++pointer_to_current_node;
                this->pointer_to_current_node = this->pointer_to_current_node->m_next;
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            virtual const iterator_postorder operator++(int) {
                iterator tmp = *this;
                this->pointer_to_current_node = this->pointer_to_current_node->m_next;
                return tmp;
            }
        };  // END OF CLASS ITERATOR_POSTORDER

        iterator_preorder begin_preorder() {
            return iterator_preorder{root};
        }

        iterator_preorder end_preorder() {
            return iterator_preorder{nullptr};
        }

        iterator_inorder begin_inorder() {
            return iterator_inorder{root};
        }

        iterator_inorder end_inorder() {
            return iterator_inorder{nullptr};
        }

        iterator_postorder begin_postorder() {
            return iterator_postorder{root};

        }

        iterator_postorder end_postorder() {
            return iterator_postorder{nullptr};

        }

        ~BinaryTree() {}


    };
}