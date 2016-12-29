/*
 * Implement Queue with Two Stack data structure.
 * offer() : add a new element to Queue
 * poll() : retrieve and remove the front element in Queue.
 * peek() : retrieve the front element in Queue.
 * size() : get size of this queue.
 * isEmpty() : check whether the queue is empty or not
 */
import java.util.Stack;
import java.util.Scanner;

class QueueWithStack<T> {
  private Stack<T> newItemStack;
  private Stack<T> oldItemStack;
  private int count;

  public QueueWithStack() {
    newItemStack = new Stack<T>();
    oldItemStack = new Stack<T>();
    count = 0;
  }

  public void offer(T data) {
    oldItemStack.push(data);

    count++;
  }

  public T poll() {

    if (count <= 0)
      return null;

    if (newItemStack.isEmpty()) {
      while (!oldItemStack.isEmpty()) {
        newItemStack.push(oldItemStack.pop());
      }
    }

    count--;

    return newItemStack.pop();
  }

  public T peek() {
    if (!oldItemStack.isEmpty())
      return oldItemStack.get(0);
    else if (!newItemStack.isEmpty())
      return newItemStack.get(newItemStack.size() - 1);

    return null;
  }

  public int size() {
    return count;
  }

  public boolean isEmpty() {
    if (count <= 0)
      return true;
    return false;
  }
}

public class QueueTest {
  public static void main(String[] args) {
    QueueWithStack<Integer> queue = new QueueWithStack<Integer>();

    queue.offer(1);
    queue.offer(2);
    queue.offer(3);
    queue.offer(4);
    queue.offer(5);

    System.out.println("size : " + queue.size());

    System.out.println("poll : " + queue.poll());
    System.out.println("size : " + queue.size());
    System.out.println("peak: " + queue.peek());
    System.out.println("size: " + queue.size());
  }
}
