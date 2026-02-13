# 🔍 Inverted Index using Hash Algorithms

## 📘 Overview
An **Inverted Index** is an index data structure that stores a mapping from content—such as words or numbers—to their locations in a database, file, or a collection of documents.  
It is one of the most popular data structures used in **document retrieval systems**, especially in **search engines**, to enable **fast full-text searches**.

This project implements an **Inverted Search System** using **Hash Algorithms**, focusing on data organization and efficient retrieval.

---

## ⚙️ Project Purpose
The main goal of this project is to:
- Allow **quick search** of words across multiple documents.
- Implement **forward and inverted indexing** efficiently.
- Use **Hashing** to improve retrieval speed and reduce time complexity.

---

## 📂 Forward Indexing
During the **Forward Indexing** phase:
1. Words are extracted from the text files.
2. Each word is stored in a data structure (like a **Linked List** or **Hash Table**) along with the document name or path.
3. Repeated words are not stored multiple times — instead, their document lists are updated.
4. Each word is mapped with all the files it appears in.

This builds an **initial word list** that links each word to one or more documents.

---

## 🔁 Inverted Indexing
The **Inverted Index** is created by transforming the forward index.  
It sorts and organizes the data to allow **quick lookups** of which documents contain a specific word.

To improve performance, **Hashing** or **Binary Search Trees (BST)** are used during indexing so that the data is **automatically organized** and **search-efficient**.

Benefits:
- Reduced search time.
- Efficient word lookup.
- Avoids maintaining separate sorted/unsorted lists on disk.

---

## 💡 Implementation Highlights
- Uses **Hash Tables** for storing and retrieving words efficiently.
- Each unique word acts as a key in the hash table.
- Each key points to a list of documents (or URLs) where the word appears.
- The system supports:
  - Adding new documents.
  - Searching for a word across all documents.
  - Viewing which documents contain the searched word.

---

## 📊 Features
✅ Efficient storage using Hashing  
✅ Fast full-text search  
✅ Avoids redundancy by updating existing entries  
✅ Simple and extendable data structure design  
✅ Ideal for understanding **search engine fundamentals**

---

## 🧠 Future Enhancements
- Include **word frequency** and **position tracking** for ranking results.
- Implement **phrase searching** using word proximity.
- Add **ranking algorithms** to display results by relevance.

---

## 🧩 Technologies Used
- **C 
- **Data Structures:** Hash Table, Linked List
- **File Handling**

---

## 🏁 Conclusion
This project demonstrates how search engines manage and retrieve data efficiently using **Inverted Indexing**.  
By implementing **Hash Algorithms**, it showcases a practical approach to building the core logic of a simple search engine.

---

## 👤 Author
**Your Name:** JAMI CHARAN TEJA  
**Project Title:** Inverted Index using Hash Algorithms  
**Category:** Data Structures Project
